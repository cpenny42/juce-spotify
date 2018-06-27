namespace spotify {

TrackSimple::TrackSimple(const var& trackJson)
: linkedFrom (trackJson["linked_from"])
{
    for (auto json : * trackJson["artists"].getArray()) {
        artists.add (ArtistSimple (json));
    }
    for (auto market : * trackJson["available_markets"].getArray()) {
        availableMarkets.add (market.toString());
    }
    for (auto namedValue : trackJson["external_urls"].getDynamicObject()->getProperties()) {
        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
    }
    
    discNumber = trackJson["disc_number"];
    durationMs = trackJson["duration_ms"];
    isExplicit = trackJson["explicit"];
    href = trackJson["href"].toString();
    id = trackJson["id"].toString();
    /* is_playable and linked_from, although in the API, don't seem to exist in any of the JSON being returned */
    //isPlayable = trackJson["is_playable"];
    //linkedFrom = std::shared_ptr<TrackLink>(new TrackLink(trackJson["linked_from"]));
    name = trackJson["name"].toString();
    if(!trackJson["preview_url"].isVoid()) {
        previewUrl = trackJson["preview_url"].toString();
    }
    trackNumber = trackJson["track_number"];
    type = trackJson["type"].toString();
    uri = trackJson["uri"].toString();
}
    
TrackSimple::TrackSimple (const TrackSimple& other)
: artists (other.artists)
, availableMarkets (other.availableMarkets)
, discNumber (other.discNumber)
, durationMs (other.durationMs)
, isExplicit (other.isExplicit)
, externalUrls (other.externalUrls)
, href (other.href)
, id (other.id)
, isPlayable (other.isPlayable)
, linkedFrom (other.linkedFrom)
, name (other.name)
, previewUrl (other.previewUrl)
, trackNumber (other.trackNumber)
, type (other.type)
, uri (other.uri)
{}

const Array<ArtistSimple>& TrackSimple::GetArtists() const
{
    return artists;
}

const StringArray& TrackSimple::GetAvailableMarkets() const
{
    return availableMarkets;
}

int TrackSimple::GetDiscNumber() const
{
    return discNumber;
}

int TrackSimple::GetDurationMs() const
{
    return durationMs;
}

bool TrackSimple::IsExplicit() const
{
    return isExplicit;
}

const StringPairArray& TrackSimple::GetExternalUrls() const
{
    return externalUrls;
}

const String& TrackSimple::GetHref() const
{
    return href;
}

const String& TrackSimple::GetId() const
{
    return id;
}

bool TrackSimple::IsPlayable() const
{
    return isPlayable;
}

const TrackLink& TrackSimple::GetLinkedFrom() const
{
    return linkedFrom;
}

const String& TrackSimple::GetName() const
{
    return name;
}

const String& TrackSimple::GetPreviewUrl() const
{
    return previewUrl;
}

int TrackSimple::GetTrackNumber() const
{
    return trackNumber;
}

const String& TrackSimple::GetType() const
{
    return type;
}

const String& TrackSimple::GetUri() const
{
    return uri;
}
    
}
