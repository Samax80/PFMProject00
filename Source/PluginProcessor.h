/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/
/*
TODO:
click anywhere on the window, and  play a note
automation should update window display
if you click and drag,it'll change the pitch of the note
save plugin state when exisitng DAW
load plugin state whn loading a session
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class Pfmproject00AudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Pfmproject00AudioProcessor();
    ~Pfmproject00AudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
	
	AudioParameterBool* shouldPlaySound= nullptr ;
	AudioParameterFloat* bgColor = nullptr;
	
	static void UpdateAutomatableParameter(RangedAudioParameter*, float value);
private:
	AudioProcessorValueTreeState apvts;
	Random r;
	
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pfmproject00AudioProcessor)
};
