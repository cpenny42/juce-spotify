namespace spotify {

class SavedTrack
{
public:
    SavedTrack (const juce::var& trackJson);
    SavedTrack (const SavedTrack& other);
    
    const juce::String& GetAddedAt() const;
    const Track& GetTrack() const;

private:
    juce::String addedAt;
    Track track;
};

}
