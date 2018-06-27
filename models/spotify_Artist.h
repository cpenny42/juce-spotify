namespace spotify {

class Artist : public ArtistSimple
{
public:
    Artist(){}
    Artist (const juce::var& artistJson);
    Artist (const Artist& other);

    int GetPopularity() const;
    const Followers& GetFollowers() const;
    const juce::StringArray& GetGenres() const;
    const juce::Array<spotify::Image>& GetImages() const;

private:

    Followers followers;
    juce::StringArray genres;
    juce::Array<spotify::Image> images;
    int popularity;

};

}
