namespace spotify {

TrackLink::TrackLink(const var& trackJson)
{
//    for (auto namedValue : trackJson["external_urls"].getDynamicObject()->getProperties()) {
//        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
//    }
    
    href = trackJson["href"].toString();
    id = trackJson["id"].toString();
    type = trackJson["type"].toString();
    uri = trackJson["uri"].toString();
}
    
TrackLink::TrackLink (const TrackLink& other)
: externalUrls (other.externalUrls)
, href (other.href)
, id (other.id)
, type (other.id)
, uri (other.id)
{}

const StringPairArray& TrackLink::GetExternalUrls() const
{
    return externalUrls;
}

const String& TrackLink::GetHref() const
{
    return href;
}

const String& TrackLink::GetId() const
{
    return id;
}

const String& TrackLink::GetType() const
{
    return type;
}

const String& TrackLink::GetUri() const
{
    return uri;
}

}
