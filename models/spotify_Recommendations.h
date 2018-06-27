namespace spotify {
    
class Recommendations
{
public:
    Recommendations (const juce::var& reccomendationsJson);
    Recommendations (const Recommendations& other);
    
    const juce::Array<RecommendationsSeed>& GetSeeds() const;
    const juce::Array<Track>& GetTracks() const;

private:
    juce::Array<RecommendationsSeed> seeds;
    juce::Array<Track> tracks;
};

}
