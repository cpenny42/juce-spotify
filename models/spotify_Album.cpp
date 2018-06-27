namespace spotify
{

Album::Album(const var& albumJson) : AlbumSimple::AlbumSimple(albumJson)
{
    for(auto json : * albumJson["copyrights"].getArray()) {
        copyrights.add(Copyright (json));
    }
    for (auto namedValue : albumJson["external_ids"].getDynamicObject()->getProperties()) {
        externalIds.set(namedValue.name.toString(), namedValue.value.toString());
    }
    for(auto genre : * albumJson["genres"].getArray()) {
        genres.add(genre.toString());
    }
    popularity = albumJson["popularity"];
    releaseDate = albumJson["release_date"].toString();
    releaseDatePrecision = albumJson["release_date_precision"].toString();
//    tracks = Pager<TrackSimple>(albumJson["tracks"]);
}
    
Album::Album (const Album& other)
: AlbumSimple (other)
, copyrights (other.copyrights)
, externalIds (other.externalIds)
, genres (other.genres)
, label (other.label)
, popularity (other.popularity)
, releaseDate (other.releaseDate)
, releaseDatePrecision (other.releaseDatePrecision)
, tracks (other.tracks)
{}

Album::~Album() = default;

const Array<Copyright>& Album::GetCopyrights() const
{
    return copyrights;
}

const StringPairArray& Album::GetExternalIds() const
{
    return externalIds;
}

const StringArray& Album::GetGenres() const
{
    return genres;
}

const String& Album::GetLabel() const
{
    return label;
}

int Album::GetPopularity() const
{
    return popularity;
}

const String& Album::GetReleaseDate() const
{
    return releaseDate;
}

const String& Album::GetReleaseDatePrecision() const
{
    return releaseDatePrecision;
}

const Pager<TrackSimple>& Album::GetTracks() const
{
    return tracks;
}

}
