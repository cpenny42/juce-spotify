namespace spotify {

ArtistSimple::ArtistSimple(const var& artistJson)
{
    for (auto namedValue : artistJson["external_urls"].getDynamicObject()->getProperties()) {
        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
    }
    
    href = artistJson["href"].toString();
    id = artistJson["id"].toString();
    name = artistJson["name"].toString();
    type = artistJson["type"].toString();
    uri = artistJson["uri"].toString();
}

ArtistSimple::ArtistSimple (const ArtistSimple& other)
: externalUrls (other.externalUrls)
, href (other.href)
, id (other.id)
, name (other.name)
, type (other.type)
, uri (other.uri)
{}
    
const StringPairArray& ArtistSimple::GetExternalUrls() const
{
    return externalUrls;
}

const String& ArtistSimple::GetHref() const
{
    return href;
}

const String& ArtistSimple::GetId() const
{
    return id;
}

const String& ArtistSimple::GetName() const
{
    return name;
}

const String& ArtistSimple::GetType() const
{
    return type;
}

const String& ArtistSimple::GetUri() const
{
    return uri;
}

}
