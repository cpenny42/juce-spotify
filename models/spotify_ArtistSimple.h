namespace spotify {

class ArtistSimple
{
public:
    ArtistSimple(){}
    ArtistSimple (const juce::var& artistJson);
    ArtistSimple (const ArtistSimple& other);
    
    const juce::StringPairArray& GetExternalUrls() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::String& GetName() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;

private:
    juce::StringPairArray externalUrls;
    juce::String href;
    juce::String id;
    juce::String name;
    juce::String type;
    juce::String uri;
};

}
