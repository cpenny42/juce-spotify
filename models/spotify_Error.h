namespace spotify {
    
class Error
{
public:
    Error (const juce::var& pagerJson);
    Error (const Error& other);

    int GetStatus() const;
    const juce::String& GetMessage() const;

private:
    int status;
    juce::String message;
};

}
