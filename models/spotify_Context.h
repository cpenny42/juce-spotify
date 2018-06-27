namespace spotify {

class Context
{
public:
    Context(){}
    Context (const juce::var& contextJson);
    Context (const Context& other);
    
    const juce::String& GetUri() const;
    const juce::String& GetHref() const;
    const juce::String& GetType() const;
    const juce::StringPairArray& GetExternalUrls() const;

private:
    juce::String uri;
    juce::String href;
    juce::String type;
    juce::StringPairArray externalUrls;
};

}
