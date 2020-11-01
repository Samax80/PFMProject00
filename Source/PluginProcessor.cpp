/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfmproject00AudioProcessor::Pfmproject00AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),
#endif
	apvts(*this, nullptr)
{
	//shouldPlaySound = new AudioParameterBool("shouldPlaySound", "shouldPlaySound", false);//  parameters of AudioParameterBool :const String& parameterID, const String& parameterName, bool defaultValue
	//addParameter(shouldPlaySound);
	auto shouldPlaySoundParam = std::make_unique<AudioParameterBool>("ShouldPlaySoundParam", "shouldPlaySoundParam", false);
	auto* param = apvts.createAndAddParameter(std::move(shouldPlaySoundParam));
	
	shouldPlaySound = dynamic_cast<AudioParameterBool*> (param);

	auto bgColorParam = std::make_unique<AudioParameterFloat>("Background Color", "Background Color", 0.f, 0.1f, 0.5f);
	param = apvts.createAndAddParameter(std::move(bgColorParam));
	bgColor = dynamic_cast<AudioParameterFloat*>(param);

	apvts.state = ValueTree("PFMSynthValueTree");
}
Pfmproject00AudioProcessor::~Pfmproject00AudioProcessor()
{
}

//==============================================================================
const String Pfmproject00AudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool Pfmproject00AudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool Pfmproject00AudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool Pfmproject00AudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double Pfmproject00AudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int Pfmproject00AudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int Pfmproject00AudioProcessor::getCurrentProgram()
{
	return 0;
}

void Pfmproject00AudioProcessor::setCurrentProgram(int index)
{
}

const String Pfmproject00AudioProcessor::getProgramName(int index)
{
	return {};
}

void Pfmproject00AudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void Pfmproject00AudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..
}

void Pfmproject00AudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Pfmproject00AudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	// This is the place where you check if the layout is supported.
	// In this template code we only support mono or stereo.
	if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
		return false;

	// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void Pfmproject00AudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	
	

	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// This is here to avoid people getting screaming feedback
	// when they first compile a plugin, but obviously you don't need to keep
	// this code if your algorithm always overwrites all the output channels.
	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...
	// Make sure to reset the state if your inner loop is processing
	// the samples and the outer loop is handling the channels.
	// Alternatively, you can process the samples with the channels
	// interleaved by keeping the same state.
	Random r;
	
	

	for (int i = 0; i < buffer.getNumSamples(); ++i)
	{
		
		
		auto noise = r.nextFloat();
     for(int channel = 0;channel< buffer.getNumChannels(); ++channel)
	 {
		 noise = channel == 1 ? r.nextFloat() : 0;//if channel is 0(left) noise value  will be  r.nextFloat() else (right channel) will be 0.

		 //paner value 0-90
		
		 

		
		 
		 if (shouldPlaySound->get())//if value is returned( is true ) and  buffer is updated with random noise
		 {
			 buffer.setSample(channel, i, noise);
		 }
		 else
		 {
			 buffer.setSample(channel, i, 0);
		 }
	 }

	}
}

//==============================================================================
bool Pfmproject00AudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Pfmproject00AudioProcessor::createEditor()
{
	return new Pfmproject00AudioProcessorEditor(*this);
}

//==============================================================================
void Pfmproject00AudioProcessor::getStateInformation(MemoryBlock& destData)
{
	

	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.

	DBG(apvts.state.toXmlString());
	MemoryOutputStream mos(destData, false);
	apvts.state.writeToStream(mos);
}

void Pfmproject00AudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.

	MemoryBlock mb(data, static_cast<size_t>(sizeInBytes));//we did a cast(static) from int to size_t
	MemoryInputStream mis(mb, false);
	apvts.state.readFromStream(mis);
}

/*Updates the Parameter and notifying the Host to  correctly handle the  automation  */
void Pfmproject00AudioProcessor::UpdateAutomatableParameter(RangedAudioParameter* param, float value)
{
	param->beginChangeGesture();
	param->setValueNotifyingHost(value);
	param->endChangeGesture();
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new Pfmproject00AudioProcessor();
}
