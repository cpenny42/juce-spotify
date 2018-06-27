namespace spotify {
    
class CurrentlyPlayingTrack
{
public:
    CurrentlyPlayingTrack(){}
    CurrentlyPlayingTrack (const juce::var& currentlyPlayingJson);
    CurrentlyPlayingTrack (const CurrentlyPlayingTrack& other);
    
    int GetTimestamp() const;
    int GetProgressMs() const;
    bool IsPlaying() const;
    const Context& GetContext() const;
    const Track& GetItem() const;
    
    bool isValid() const;

private:
    int timestamp;
    int progressMs;
    bool isPlaying;
    Context context;
    Track item;
};

}
