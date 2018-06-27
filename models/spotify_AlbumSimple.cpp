namespace spotify {
    
AlbumSimple::AlbumSimple(const var& albumJson)
{
    albumType = albumJson["album_type"].toString();
    
    for(auto json : * albumJson["artists"].getArray()) {
        artists.add (ArtistSimple (json));
    }

    for (auto market : * albumJson["available_markets"].getArray()) {
        availableMarkets.add (market.toString());
    }

    for (auto namedValue : albumJson["external_urls"].getDynamicObject()->getProperties()) {
        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
    }

    for (auto json : * albumJson["images"].getArray()) {
        images.add (spotify::Image (json));
    }
    
    href = albumJson["href"].toString();
    id = albumJson["id"].toString();
    name = albumJson["name"].toString();
    type = albumJson["type"].toString();
    uri = albumJson["uri"].toString();
}
    
AlbumSimple::AlbumSimple (const AlbumSimple& other)
: albumType (other.albumType)
, artists (other.artists)
, availableMarkets (other.availableMarkets)
, externalUrls (other.externalUrls)
, href (other.href)
, id (other.id)
, images (other.images)
, name (other.name)
, type (other.type)
, uri (other.uri)
{}

const String& AlbumSimple::GetAlbumType() const
{
    return albumType;
}

const String& AlbumSimple::GetHref() const
{
    return href;
}

const String& AlbumSimple::GetId() const
{
    return id;
}

const String& AlbumSimple::GetName() const
{
    return name;
}

const String& AlbumSimple::GetType() const
{
    return type;
}

const String& AlbumSimple::GetUri() const
{
    return uri;
}

const Array<spotify::Image>& AlbumSimple::GetImages() const
{
    return images;
}

const Array<ArtistSimple>& AlbumSimple::GetArtists() const
{
    return artists;
}
    
const StringArray& AlbumSimple::GetAvailableMarkets() const
{
    return availableMarkets;
}

const StringPairArray& AlbumSimple::GetExternalUrls() const
{
    return externalUrls;
}

}
