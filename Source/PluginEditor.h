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
		
	/// <summary>
	/// Mouses up.
	/// </summary>
	/// <param name="e">The e.</param>
	void mouseUp(const MouseEvent& e) override;
		
	/// <summary>
	/// Mouses down.
	/// </summary>
	/// <param name="e">The e.</param>
	void mouseDown(const MouseEvent& e) override;
	/// <summary>
/// Manages the position when Mouse is dragged.
/// </summary>
/// <param name="e">The e.</param>
	void mouseDrag(const MouseEvent& e) override;//manage the mousedrag event

private:
	Point<int> lastClickPosition;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Pfmproject00AudioProcessor& processor;	
	/// <summary>
	/// The cached bg color,variable used to change the color of background
	/// </summary>
	float cachedBgColor = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pfmproject00AudioProcessorEditor)
};
