/*
  ==============================================================================

    AudioDevEffectBase.h
    Created: 4 Nov 2020 10:17:51am
    Author:  Kijiji

  ==============================================================================
*/

#pragma once
#include<algorithm>

 class AudioDevEffectBase
{
public:
	virtual void  PrepareForPlayback(float& sampleRate) = 0;

	virtual void  ProcessAudioSample(float& sample) = 0;


};