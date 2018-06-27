namespace spotify {

class AlbumSimple;

class Track : public TrackSimple
{
public:
    Track() {}
    Track (const juce::var& trackJson);
    Track (const Track& other);
    ~Track();

    const AlbumSimple& GetAlbum() const;
    const juce::StringPairArray& GetExternalIds() const;
    int GetPopularity() const;

private:
    
    AlbumSimple album;
    juce::StringPairArray externalIds;
    int popularity;
};

}
