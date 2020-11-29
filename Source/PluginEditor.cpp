/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfmproject00AudioProcessorEditor::Pfmproject00AudioProcessorEditor(Pfmproject00AudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{

    InitializeSlider(mGainSlider, Slider::TextBoxBelow, true, 50, 20, Slider::SliderStyle::LinearVertical, 0.0f, 1.0f, 0.01, 0.5f);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(200, 300);//here we set the size of the plugin window  
}

Pfmproject00AudioProcessorEditor::~Pfmproject00AudioProcessorEditor()
{
}

//==============================================================================
void Pfmproject00AudioProcessorEditor::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    auto backGroundColor = Colours::black;
    g.fillAll(backGroundColor);

}

void Pfmproject00AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    mGainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void Pfmproject00AudioProcessorEditor::InitializeSlider(Slider& mGainSlider, juce::Slider::TextEntryBoxPosition newPosition, bool isReadOnly, int textEntryBoxWidth, int textEntryBoxHeight, juce::Slider::SliderStyle newStyle, double newMin, double newMax, double newInt, double newValue)
{
    mGainSlider.setSliderStyle(newStyle);
    mGainSlider.setTextBoxStyle(newPosition, isReadOnly, textEntryBoxWidth, textEntryBoxHeight);
    mGainSlider.setRange(newMin, newMax, newInt);
    mGainSlider.setValue(newValue);
    addAndMakeVisible(mGainSlider);//this makes the child fo the component visible.
}





