namespace spotify {

class TrackSimple;

class Album : public AlbumSimple
{
public:
    Album() {}
    Album(const juce::var& albumJson);
    Album(const Album& other);
    ~Album();

    const juce::Array<Copyright>& GetCopyrights() const;
    const juce::StringPairArray& GetExternalIds() const;
    const juce::StringArray& GetGenres() const;
    const juce::String& GetLabel() const;
    int GetPopularity() const;
    const juce::String& GetReleaseDate() const;
    const juce::String& GetReleaseDatePrecision() const;
    const Pager<TrackSimple>& GetTracks() const;

private:

    juce::Array<Copyright> copyrights;
    juce::StringPairArray externalIds;
    juce::StringArray genres;
    juce::String label;
    int popularity;
    juce::String releaseDate;
    juce::String releaseDatePrecision;
    Pager<TrackSimple> tracks;

};

}
