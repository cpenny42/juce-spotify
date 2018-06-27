namespace spotify {
    
class PlayHistoryObject
{
public:
    PlayHistoryObject(const juce::var& playHistoryJson);

    TrackSimple GetTrack() const;
    juce::String GetPlayedAt() const;
    Context GetContext() const;

private:
    TrackSimple track;
    juce::String playedAt;
    Context context;
};

}
