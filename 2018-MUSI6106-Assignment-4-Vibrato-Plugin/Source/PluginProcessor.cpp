/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VibratopluginAudioProcessor::VibratopluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                  ),
treeState(*this, nullptr),
parameters(*this, nullptr)
#endif
{
    CVibrato::createInstance(m_pCVibrato);
    NormalisableRange<float> widthRange(0.0f, 10.0f);
    treeState.createAndAddParameter(MOD_WIDTH_ID, MOD_WIDTH_NAME, MOD_WIDTH_NAME, widthRange, m_fInitialModWidthValue, nullptr, nullptr);
    NormalisableRange<float> freqRange(0.0f, 25.0f);
    treeState.createAndAddParameter(MOD_FREQ_ID, MOD_FREQ_NAME, MOD_FREQ_NAME, freqRange, m_fInitialModFreqValue, nullptr, nullptr);
    
    parameters.state = ValueTree("savedParams");
}

VibratopluginAudioProcessor::~VibratopluginAudioProcessor()
{
    CVibrato::destroyInstance(m_pCVibrato);
    m_pCVibrato = NULL;
}

//==============================================================================
const String VibratopluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VibratopluginAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool VibratopluginAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool VibratopluginAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double VibratopluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VibratopluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int VibratopluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VibratopluginAudioProcessor::setCurrentProgram (int index)
{
}

const String VibratopluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void VibratopluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VibratopluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    m_pCVibrato->initInstance(m_fMaxDelayValue, this->getSampleRate(), this->getTotalNumInputChannels());
    m_pCVibrato->setParam(CVibrato::kParamModWidthInS, m_fInitialModWidthValue/1000);
    m_pCVibrato->setParam(CVibrato::kParamModFreqInHz, m_fInitialModFreqValue);
}

void VibratopluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VibratopluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
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

void VibratopluginAudioProcessor:: processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        // ..do something to the data...
    }
    

    m_pCVibrato->process((float **)buffer.getArrayOfReadPointers(), buffer.getArrayOfWritePointers(), buffer.getNumSamples());

}

//==============================================================================
bool VibratopluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VibratopluginAudioProcessor::createEditor()
{
    return new VibratopluginAudioProcessorEditor (*this);
}

//==============================================================================
void VibratopluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    copyXmlToBinary(*xml, destData);
}

void VibratopluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    ScopedPointer<XmlElement> theParams (getXmlFromBinary(data, sizeInBytes));
    
    if (theParams != nullptr) {
        if (theParams -> hasTagName(parameters.state.getType())) {
            parameters.state = ValueTree::fromXml(*theParams);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VibratopluginAudioProcessor();
}

void VibratopluginAudioProcessor::setVibratoParam(CVibrato::VibratoParam_t eParam, float fParamValue)
{
    m_pCVibrato->setParam(eParam, fParamValue);
}


void VibratopluginAudioProcessor::setBypass(bool bState)
{
    m_bIfBypass = bState;
}


bool VibratopluginAudioProcessor::getBypass()
{
    return m_bIfBypass;
}
