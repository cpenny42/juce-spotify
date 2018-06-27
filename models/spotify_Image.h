namespace spotify {
    
class Image
{
public:
    Image () {}
    Image (const juce::var& imageJson);
    Image (const spotify::Image& other);
    
    const juce::String& GetUrl() const;
    int GetHeight() const;
    int GetWidth() const;

private:
    juce::String url;
    int height;
    int width;
};

}
