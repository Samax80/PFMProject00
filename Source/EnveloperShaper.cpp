/*
  ==============================================================================

    EnveloperShaper.cpp
    Created: 4 Nov 2020 10:20:49am
    Author:  Samax80

  ==============================================================================
*/

#include "EnveloperShaper.h"


void EnveloperShaper::PrepareForPlayback(float& sampleRate)
{
	m_sampleRate = sampleRate;
	update();
}

void EnveloperShaper::ProcessAudioSample(float& sample)
{
	if (sample > m_Envelope)
	{
		m_Envelope += m_Attack * (sample - m_Envelope);//+
	}
	else if (sample < m_Envelope)
	{
		m_Envelope += m_Release * (sample - m_Envelope);//-
	}
	sample = m_Envelope;
}

void EnveloperShaper::SetAttack(float attack)
{
	m_AttackInMiliseconds = attack;
	update();
}

void EnveloperShaper::SetRelease(float release)
{
	m_ReleaseInMiliseconds = release;
	update();
}

void EnveloperShaper::update()
{
	m_Attack = calculate(m_AttackInMiliseconds);

	m_Release = calculate(m_ReleaseInMiliseconds);
}

float EnveloperShaper::calculate(float time)
{
	if (time <= 0.f || m_sampleRate <= 0.f)
	{
		return 1.f;
	}

	return 1.f - exp(-1.f / (time * 0.001f * m_sampleRate));
}
