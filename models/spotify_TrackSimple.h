namespace spotify {
    
class TrackSimple
{
public:
    TrackSimple() {}
    TrackSimple (const juce::var& trackJson);
    TrackSimple (const TrackSimple& other);
    
    const juce::Array<ArtistSimple>& GetArtists() const;
    const juce::StringArray& GetAvailableMarkets() const;
    int GetDiscNumber() const;
    int GetDurationMs() const;
    bool IsExplicit() const;
    const juce::StringPairArray& GetExternalUrls() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    bool IsPlayable() const;
    const TrackLink& GetLinkedFrom() const;
    const juce::String& GetName() const;
    const juce::String& GetPreviewUrl() const;
    int GetTrackNumber() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;

private:
    juce::Array<ArtistSimple> artists;
    juce::StringArray availableMarkets;
    int discNumber;
    int durationMs;
    bool isExplicit;
    juce::StringPairArray externalUrls;
    juce::String href;
    juce::String id;
    bool isPlayable;
    TrackLink linkedFrom;
    juce::String name;
    juce::String previewUrl;
    int trackNumber;
    juce::String type;
    juce::String uri;
};

}
