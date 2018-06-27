namespace spotify {
    
Track::Track(const var& trackJson)
: TrackSimple::TrackSimple(trackJson)
, album (trackJson["album"])
{
    popularity = trackJson["popularity"];
    for (auto namedValue : trackJson["external_ids"].getDynamicObject()->getProperties()) {
        externalIds.set(namedValue.name.toString(), namedValue.value.toString());
    }
}
    
Track::Track (const Track& other)
: TrackSimple (other)
, album (other.album)
, externalIds (other.externalIds)
, popularity (other.popularity)
{}

Track::~Track() = default;

const AlbumSimple& Track::GetAlbum() const
{
    return album;
}

const StringPairArray& Track::GetExternalIds() const
{
    return externalIds;
}

int Track::GetPopularity() const
{
    return popularity;
}

}
