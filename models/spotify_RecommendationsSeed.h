namespace spotify {

class RecommendationsSeed
{
public:
    RecommendationsSeed (const juce::var& reccomendationsJson);
    RecommendationsSeed (const RecommendationsSeed& other);
    
    int GetAfterFilteringSize() const;
    int GetAfterRelinkingSize() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    int GetInitialPoolSize() const;
    const juce::String& GetType() const;

private:
    int afterFilteringSize;
    int afterRelinkingSize;
    juce::String href;
    juce::String id;
    int initialPoolSize;
    juce::String type;
};

}
