namespace spotify {
    
class Copyright
{
public:
    Copyright (const juce::var& copyrightJson);
    Copyright (const Copyright& other);
    
    const juce::String& GetText() const;
    const juce::String& GetType() const;

private:
    juce::String text;
    juce::String type;
};

}
