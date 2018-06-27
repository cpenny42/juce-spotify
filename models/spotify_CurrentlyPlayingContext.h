namespace spotify {

class CurrentlyPlayingContext
{
public:
    CurrentlyPlayingContext (const juce::var& currentlyPlayingJson);
    CurrentlyPlayingContext (const CurrentlyPlayingContext& other);

    const juce::String& GetRepeatState() const;
    bool GetShuffleState() const;
    int GetTimestamp() const;
    int GetProgressMs() const;
    bool IsPlaying() const;
    const Device& GetDevice() const;
    const Context& GetContext() const;
    const Track& GetItem() const;

private:
    juce::String repeatState;
    bool shuffleState;
    int timestamp;
    int progressMs;
    bool isPlaying;
    Device device;
    Context context;
    Track item;
};

}
