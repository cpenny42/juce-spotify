namespace spotify {

class PlaylistSimple
{
public:
    PlaylistSimple (const juce::var& playlistJson);
    PlaylistSimple (const PlaylistSimple& other);
    
    bool IsCollaborative() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::String& GetName() const;
    bool IsPublic() const;
    const juce::String& GetSnapshotId() const;
    const Pager<PlaylistTrack>& GetTracks() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;
    const UserPublic& GetOwner() const;
    const juce::StringPairArray& GetExternalUrls() const;
    const juce::Array<spotify::Image>& GetImages() const;

private:
    bool isCollaborative;
    juce::String href;
    juce::String id;
    juce::String name;
    bool isPublic;
    juce::String snapshotId;
    Pager<PlaylistTrack> tracks;
    juce::String type;
    juce::String uri;
    juce::Array<spotify::Image> images;
    juce::StringPairArray externalUrls;
    UserPublic owner;
};

}
