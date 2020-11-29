/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor. 

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Pfmproject00AudioProcessorEditor : public AudioProcessorEditor
{
public:
    Pfmproject00AudioProcessorEditor(Pfmproject00AudioProcessor&);
    ~Pfmproject00AudioProcessorEditor();

    //==============================================================================
    void paint(Graphics&) override;
    void resized() override;

    void InitializeSlider(Slider& mGainSlider, juce::Slider::TextEntryBoxPosition newPosition, bool isReadOnly, int textEntryBoxWidth, int textEntryBoxHeight, juce::Slider::SliderStyle newStyle, double newMin, double newMax, double newInt, double newValue);
private:
    /// <summary>
    /// The Gain slider Object 
    /// </summary>
    Slider mGainSlider;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it!
    Pfmproject00AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Pfmproject00AudioProcessorEditor)
};
