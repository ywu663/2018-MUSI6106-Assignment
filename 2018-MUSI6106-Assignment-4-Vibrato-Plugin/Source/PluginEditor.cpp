/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VibratopluginAudioProcessorEditor::VibratopluginAudioProcessorEditor (VibratopluginAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //Automation
    sliderAttachWidth = new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, MOD_WIDTH_ID, modWidthSlider);
    sliderAttachFreq = new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, MOD_FREQ_ID, modFreqSlider);
    
    //Mod Width
    addAndMakeVisible(modWidthSlider);
    //Mod Width 0.0 - 10.0 ms
    modWidthSlider.setRange(0.0f, 10.0f, 0.1);
    modWidthSlider.setTextValueSuffix(" ms");
    modWidthSlider.addListener(this);
    addAndMakeVisible(modFreqLabel);
    modWidthLabel.setText("Mod Width", dontSendNotification);
    modWidthLabel.attachToComponent(&modWidthSlider, true);
    
    
    
    //Mod Freq
    addAndMakeVisible(modFreqSlider);
    //LFO 0 - 25 Hz
    modFreqSlider.setRange(0.0f, 25.0f, 0.1);
    modFreqSlider.setTextValueSuffix(" Hz");
    modFreqSlider.addListener(this);
    addAndMakeVisible(modFreqLabel);
    modFreqLabel.setText("Mod Freq", dontSendNotification);
    modFreqLabel.attachToComponent(&modFreqSlider, true);
    
    //By Pass
    addAndMakeVisible(byPassButton);
    byPassButton.setToggleState(0, dontSendNotification);
    byPassButton.addListener(this);
    addAndMakeVisible(byPassLabel);
    byPassLabel.setText("Bypass", dontSendNotification);
    byPassLabel.attachToComponent(&byPassButton, true);
    
}

VibratopluginAudioProcessorEditor::~VibratopluginAudioProcessorEditor()
{
    delete sliderAttachWidth;
    sliderAttachWidth = NULL;
    delete sliderAttachFreq;
    sliderAttachFreq = NULL;
}

//==============================================================================
void VibratopluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void VibratopluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    const int border = 120;
    modWidthSlider.setBounds(border, 20, getWidth() - border, 20);
    modFreqSlider.setBounds(border, 50, getWidth() - border, 50);
    byPassButton.setBounds(border, 100, getWidth() - border, 50);
}

void VibratopluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &modWidthSlider)
    {
        processor.setVibratoParam(CVibrato::kParamModWidthInS, (float)slider->getValue()/1000);
    }
    else if (slider == &modFreqSlider)
    {
        processor.setVibratoParam(CVibrato::kParamModFreqInHz, (float)slider->getValue());
    }
}

void VibratopluginAudioProcessorEditor::buttonClicked(Button* button)
{
    if (button == &byPassButton)
    {
        processor.setBypass(button->getToggleState());
    }
}


