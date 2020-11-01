/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfmproject00AudioProcessorEditor::Pfmproject00AudioProcessorEditor (Pfmproject00AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	cachedBgColor = processor.bgColor->get();
    setSize (400, 300);
}

/// <summary>
/// Finalizes an instance of the <see cref="Pfmproject00AudioProcessorEditor" /> class.
/// </summary>
Pfmproject00AudioProcessorEditor::~Pfmproject00AudioProcessorEditor()
{	
	//OLD WAY
	//processor.shouldPlaySound->beginChangeGesture();
	//processor.shouldPlaySound->setValueNotifyingHost(false); //if the GUI is closed the  processor.shouldPlaySound  will be set to false.
	//processor.shouldPlaySound->endChangeGesture();

	//NEW WAY
	Pfmproject00AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound, false);
}

//==============================================================================
//
void Pfmproject00AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId).interpolatedWith(Colours::white,cachedBgColor*8));//Tis method will interpolate the actual background color betwwen two colors

    g.setColour (Colours::white);
    g.setFont (19.0f);
    g.drawFittedText ("CHANGE BACKGROUND COLOR", getLocalBounds(), Justification::centred, 1);
}

void Pfmproject00AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

/// <summary>
///  play sound when the Mouse Up.
/// </summary>
/// <param name="e">The e mouse event </param>

void Pfmproject00AudioProcessorEditor::mouseUp(const MouseEvent& e)
{
	//	DBG("mouse is Up");
		//OlD WAY
		//processor.shouldPlaySound->beginChangeGesture();
		//processor.shouldPlaySound->setValueNotifyingHost( !processor.shouldPlaySound->get());// If not true,will  No sound  will play!! !
		//processor.shouldPlaySound->endChangeGesture();

		//NEW WAY uncomment to get noise when  mouse click is performed!!!
	Pfmproject00AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound, !processor.shouldPlaySound->get());//!processor.shouldPlaySound->get() EVEN IS A BOOL A FLOAT VALUE  WILL BE RETURN WHEN TRUE =1 OR FALSE =0
}

/// <summary>
/// play sound when the Mouse down.
/// </summary>
/// <param name="e">The e mouse event</param>

void Pfmproject00AudioProcessorEditor::mouseDown(const MouseEvent& e)
{
	//DBG("mouse is Down");//True!!
	lastClickPosition = e.getPosition();//Constant value until dmouseclick is released.

}


/// <summary>
/// Mouses the drag.
/// </summary>
/// <param name="e">The e.</param>
void Pfmproject00AudioProcessorEditor::mouseDrag(const MouseEvent& e)
{
	
	auto clickPos = e.getPosition();
	DBG(clickPos.toString());//show at screen the value of clickPos as string!!
	auto difY = jlimit(-1.0, 1.0, -(clickPos.y - lastClickPosition.y) / 200.0);
	difY = jmap(difY, -1.0, 1.0, 0.0, 1.0);
	DBG("dify:" << difY);
	DBG("clickPos.y" << clickPos.y);
	DBG("lastClickPosition.y" << lastClickPosition.y);



	Pfmproject00AudioProcessor::UpdateAutomatableParameter(processor.bgColor, difY);
	cachedBgColor = processor.bgColor->get();
	repaint();
}
