namespace spotify {

class Category
{
public:
    Category (const juce::var& copyrightJson);
    Category (const Category& other);
    
    const juce::String& GetHref() const;
    const juce::String& GetId() const;
    const juce::String& GetName() const;
    const juce::Array<spotify::Image>& GetIcons() const;

private:
    juce::String href;
    juce::String id;
    juce::String name;
    juce::Array<spotify::Image> icons;
};


}
