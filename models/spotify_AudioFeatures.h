namespace spotify {

class AudioFeatures
{
public:
    AudioFeatures(){}
    AudioFeatures (const juce::var& audioFeaturesJson);
    AudioFeatures (const AudioFeatures& other);
    
    float GetAcousticness() const;
    const juce::String& GetAnalysisUrl() const;
    float GetDanceability() const;
    int GetDurationMs() const;
    float GetEnergy() const;
    const juce::String& GetId() const;
    float GetInstrumentalness() const;
    int GetKey() const;
    float GetLiveness() const;
    float GetLoudness() const;
    int GetMode() const;
    float GetSpeechiness() const;
    float GetTempo() const;
    int GetTimeSignature() const;
    const juce::String& GetTrackHref() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;
    float GetValence() const;
    bool isMajorKey() const;

private:
    
    float acousticness;
    juce::String analysisUrl;
    float danceability;
    int durationMs;
    float energy;
    juce::String id;
    float instrumentalness;
    int key;
    float liveness;
    float loudness;
    int mode;
    float speechiness;
    float tempo;
    int timeSignature;
    juce::String trackHref;
    juce::String type;
    juce::String uri;
    float valence;
};

}
