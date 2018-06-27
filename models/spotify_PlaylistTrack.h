namespace spotify {

class PlaylistTrack
{
public:
    PlaylistTrack (const juce::var& trackJson);
    PlaylistTrack (const PlaylistTrack& other);
    
    const juce::String& GetAddedAt() const;
    const UserPublic& GetAddedBy() const;
    bool IsLocal() const;
    const Track& GetTrack() const;

private:
    juce::String addedAt;
    UserPublic addedBy;
    bool isLocal;
    Track track;
};

}
