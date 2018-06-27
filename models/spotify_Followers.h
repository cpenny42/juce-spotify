namespace spotify {
    
class Followers
{
public:
    Followers(){}
    Followers (const juce::var& followersJson);
    Followers (const Followers& other);

    const juce::String& GetHref() const;
    int GetTotal() const;

private:
    juce::String href;
    int total;
};

}
