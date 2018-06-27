namespace spotify {

class User : public UserPublic
{
public:
    User (const juce::var& userJson);
    User (const User& other);
    
    const juce::String& GetBirthdate() const;
    const juce::String& GetCountry() const;
    const juce::String& GetEmail() const;
    const juce::String& GetProduct() const;

private:
    juce::String birthdate;
    juce::String country;
    juce::String email;
    juce::String product;
};

}
