namespace spotify {
    
class Cursor
{
public:
    Cursor (const juce::var& cursorJson);
    Cursor (const Cursor& other);
    const juce::String& GetAfter() const;

private:
    juce::String after;
};

}
