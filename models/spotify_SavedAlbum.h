namespace spotify {
    
class SavedAlbum
{
public:
    SavedAlbum (const juce::var& albumJson);
    SavedAlbum (const SavedAlbum& other);
    
    const juce::String& GetAddedAt() const;
    const Album& GetAlbum() const;

private:
    juce::String addedAt;
    Album album;
};

}
