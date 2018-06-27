namespace spotify {
    
Artist::Artist (const var& artistJson)
: ArtistSimple::ArtistSimple(artistJson)
, followers (artistJson["followers"])
{
    for (auto genre : * artistJson["genres"].getArray()) {
        genres.add (genre.toString());
    }

    for (auto json : * artistJson["images"].getArray()) {
        images.add (spotify::Image (json));
    }
    
    popularity = artistJson["popularity"];
}

Artist::Artist (const Artist& other)
: ArtistSimple (other)
, followers (other.followers)
, genres (other.genres)
, images (other.images)
, popularity (other.popularity)
{}
    
int Artist::GetPopularity() const
{
    return popularity;
}

const Followers& Artist::GetFollowers() const
{
    return followers;
}

const StringArray& Artist::GetGenres() const
{
    return genres;
}

const Array<spotify::Image>& Artist::GetImages() const
{
    return images;
}

}
