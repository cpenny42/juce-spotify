namespace spotify {
    
class TrackLink
{
public:
    TrackLink() {}
    TrackLink (const juce::var& trackJson);
    TrackLink (const TrackLink& other);
    
    const juce::StringPairArray& GetExternalUrls() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;

private:
    juce::StringPairArray externalUrls;
    juce::String href;
    juce::String id;
    juce::String type;
    juce::String uri;
};

}
