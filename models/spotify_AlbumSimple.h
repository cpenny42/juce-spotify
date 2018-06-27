namespace spotify {
    
class AlbumSimple
{
public:
    AlbumSimple() {}
    AlbumSimple (const juce::var& albumJson);
    AlbumSimple (const AlbumSimple& other);
    
    const juce::String& GetAlbumType() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::String& GetName() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;
    const juce::Array<spotify::Image>& GetImages() const;
    const juce::Array<ArtistSimple>& GetArtists() const;
    const juce::StringArray& GetAvailableMarkets() const;
    const juce::StringPairArray& GetExternalUrls() const;

private:
    juce::String albumType;
    juce::Array<ArtistSimple> artists;
    juce::StringArray availableMarkets;
    juce::StringPairArray externalUrls;
    juce::String href;
    juce::String id;
    juce::Array<spotify::Image> images;
    juce::String name;
    juce::String type;
    juce::String uri;
};

}
