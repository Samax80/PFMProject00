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
class Pfmproject00AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Pfmproject00AudioProcessorEditor (Pfmproject00AudioProcessor&);
    ~Pfmproject00AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void mouseUp(const MouseEvent& e) override;//manage the mouseup event
	void mouseDown(const MouseEvent& e) override;//manage the mousedown event

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Pfmproject00AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pfmproject00AudioProcessorEditor)
};
