/*
  ==============================================================================

    Compressor.h
    Created: 4 Nov 2020 10:19:29am
    Author:  Kijiji

  ==============================================================================
*/

#pragma once

#include "AudioDevEffectBase.h"
#include "EnveloperShaper.h"


/// <summary>
/// Compressor Class
/// </summary>
/// <seealso cref="AudioDevEffectBase" />
class Compressor :public AudioDevEffectBase
{
public:	
	/// <summary>
	/// Prepares for playback.
	/// </summary>
	/// <param name="sampleRate">The sample rate.</param>
	void PrepareForPlayback(float& sampleRate) override;
	
	/// <summary>
	/// Processes the audio sample.
	/// </summary>
	/// <param name="sample">The sample.</param>
	void  ProcessAudioSample(float& sample) override;
	
	/// <summary>
	/// Sets the threshold.
	/// </summary>
	/// <param name="threshold">The threshold.</param>
	void SetThreshold(float threshold);
	
	/// <summary>
	/// Sets the ratio.
	/// </summary>
	/// <param name="ratio">The ratio.</param>
	void SetRatio(float ratio);
	
	/// <summary>
	/// Sets the attack.
	/// </summary>
	/// <param name="attack">The attack.</param>
	void SetAttack(float attack);
	
	/// <summary>
	/// Sets the release.
	/// </summary>
	/// <param name="release">The release.</param>
	void SetRelease(float release);

private:

	float m_Threshold = -56.f;
	float m_ratio = 2.f;
	EnveloperShaper m_EnvelopeShaper;
			
	/// <summary>
	/// Amplitudes to decibel.
	/// </summary>
	/// <param name="amplitud">The amplitud.</param>
	/// <returns></returns>
	float amplitudeToDecibel(float amplitude);
	
	/// <summary>
	/// Decibels to amplitude.
	/// </summary>
	/// <param name="decibel">The decibel.</param>
	/// <returns></returns>
	float decibelToAmplitude(float decibel);

	const float BOUND_LOG = -96.f;
	const float BOUND_LIN = decibelToAmplitude(BOUND_LOG);



	





};
