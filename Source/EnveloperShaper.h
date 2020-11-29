/*
  ==============================================================================

	EnveloperShaper.h
	Created: 4 Nov 2020 10:20:49am
	Author:  Kijiji

  ==============================================================================
*/

#pragma once
#include "AudioDevEffectBase.h"
#include<cmath>

/// <summary>
/// EnveloperShaper Class
/// </summary>
/// <seealso cref="AudioDevEffectBase" />
class EnveloperShaper :public AudioDevEffectBase
{
public:

	
	void PrepareForPlayback(float& sampleRate) override;

	void  ProcessAudioSample(float& sample) override;

	void SetAttack(float attack);

	void SetRelease(float release);

private:

	float m_Envelope = 0.f;
	float m_sampleRate = 44100.f;
	float m_AttackInMiliseconds = 10.f;
	float m_ReleaseInMiliseconds = 100.f;
	float m_Attack = 01.f;
	float m_Release = 10.f;

	void update();

	float calculate(float time);

};

