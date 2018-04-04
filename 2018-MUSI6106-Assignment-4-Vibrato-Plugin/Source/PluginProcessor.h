/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Vibrato.h"
#define MOD_WIDTH_ID "width"
#define MOD_WIDTH_NAME "Mod Width"
#define MOD_FREQ_ID "freq"
#define MOD_FREQ_NAME "Mod Freq"


//==============================================================================
/**
 */
class VibratopluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    VibratopluginAudioProcessor();
    ~VibratopluginAudioProcessor();
    
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
    
    void setVibratoParam (CVibrato::VibratoParam_t eParam, float fParamValue);
    void setBypass(bool bState);
    
    AudioProcessorValueTreeState treeState;
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VibratopluginAudioProcessor)
    
    CVibrato *m_pCVibrato = NULL;
    bool m_bIfBypass = false;
    const float m_fInitialModWidthValue = 1.2;
    const float m_fInitialModFreqValue = 10.0;
    const float m_fMaxDelayValue = 1.0;
};

