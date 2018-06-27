namespace spotify {

class UserPublic
{
public:
    UserPublic (const juce::var& userJson);
    UserPublic (const UserPublic& other);

    const juce::String& GetDisplayName() const;
    const juce::StringPairArray& GetExternalUrls() const;
    const Followers& GetFollowers() const;
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::Array<spotify::Image>& GetImages() const;
    const juce::String& GetType() const;
    const juce::String& GetUri() const;

private:
    juce::String displayName;
    juce::StringPairArray externalUrls;
    Followers followers;
    juce::String href;
    juce::String id;
    juce::Array<spotify::Image> images;
    juce::String type;
    juce::String uri;
};

}
