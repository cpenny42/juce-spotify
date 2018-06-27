namespace spotify {

class Playlist : public PlaylistSimple
{
public:
    Playlist (const juce::var& playlistJson);
    Playlist (const Playlist& other);
    
    const juce::String& GetDescription() const;
    const Followers& GetFollowers() const;

private:
    juce::String description;
    Followers followers;
};

}
