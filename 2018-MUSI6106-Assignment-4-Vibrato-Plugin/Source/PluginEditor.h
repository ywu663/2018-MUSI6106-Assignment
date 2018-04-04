/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VibratopluginAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Slider::Listener,
                                           public Button::Listener
{
public:
    VibratopluginAudioProcessorEditor (VibratopluginAudioProcessor&);
    ~VibratopluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    void buttonClicked(Button* button) override;

    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VibratopluginAudioProcessor& processor;
    Slider modWidthSlider;
    Label modWidthLabel;
    Slider modFreqSlider;
    Label modFreqLabel;
    ToggleButton byPassButton;
    Label byPassLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VibratopluginAudioProcessorEditor)
};
