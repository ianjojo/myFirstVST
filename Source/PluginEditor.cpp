/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mGainSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange (0.0f, 1.0f, 0.01f);
    mGainSlider.setValue (0.5f);
    mGainSlider.addListener(this);
    addAndMakeVisible (mGainSlider);
    setSize (200, 300);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void NewProjectAudioProcessorEditor::resized()
{
    mGainSlider.setBounds (getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mGainSlider)
    {
        processor.mGain = mGainSlider.getValue();
        
    }
}

