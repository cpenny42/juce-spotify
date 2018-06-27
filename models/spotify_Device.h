namespace spotify {

class Device
{
public:
    Device (const juce::var& deviceJson);
    Device (const Device& other);
    
    const juce::String& GetId() const;
    bool IsActive() const;
    bool IsRestricted() const;
    const juce::String& GetName() const;
    const juce::String& GetType() const;
    int GetVolumePercent() const;

private:
    juce::String id;
    bool isActive;
    bool isRestricted;
    juce::String name;
    juce::String type;
    int volumePercent;
};

}
