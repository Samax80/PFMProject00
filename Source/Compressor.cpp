/*
  ==============================================================================

    Compressor.cpp
    Created: 4 Nov 2020 10:19:29am
    Author:  Kijiji

  ==============================================================================
*/

#include "Compressor.h"

void Compressor::PrepareForPlayback(float& sampleRate)
{
	m_EnvelopeShaper.PrepareForPlayback(sampleRate);
}

/// <summary>
/// Processes the audio sample.
/// </summary>
/// <param name="sample">The sample.</param>
void Compressor::ProcessAudioSample(float& sample)
{
	float detectionSignal = sample;	

	detectionSignal = fabs(detectionSignal);

	m_EnvelopeShaper.ProcessAudioSample(detectionSignal);

	detectionSignal = amplitudeToDecibel(detectionSignal);

	if (detectionSignal > m_Threshold)
	{
		float scale = 1.f - (1.f / m_ratio);
		float gain = scale * (m_Threshold - detectionSignal);
		gain = decibelToAmplitude(gain);

		sample *= gain;
	}
}

void Compressor::SetThreshold(float threshold)
{
	m_Threshold = threshold;
}

void Compressor::SetRatio(float ratio)
{
	m_ratio = ratio;
}

void Compressor::SetAttack(float attack)
{
	m_EnvelopeShaper.SetAttack(attack);
}

void Compressor::SetRelease(float release)
{
	m_EnvelopeShaper.SetRelease(release);
}

float Compressor::amplitudeToDecibel(float amplitude)
{
	amplitude =(std::max)(amplitude,BOUND_LIN);
	
	return 20.f * log10(amplitude);
}

float Compressor::decibelToAmplitude(float decibel)
{
	return pow(10.f, decibel / 20.f);
}
