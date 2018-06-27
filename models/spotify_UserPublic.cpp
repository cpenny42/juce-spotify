namespace spotify {

UserPublic::UserPublic(const var& userJson)
: followers (userJson["followers"])
{
    if(! userJson["display_name"].isVoid()) {
        displayName = userJson["display_name"].toString();
    }
    for (auto namedValue : userJson["external_urls"].getDynamicObject()->getProperties()) {
        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
    }
    for (auto json : * userJson["images"].getArray()) {
        images.add (spotify::Image (json));
    }
    
    href = userJson["href"].toString();
    id = userJson["id"].toString();
    type = userJson["type"].toString();
    uri = userJson["uri"].toString();
}
    
UserPublic::UserPublic (const UserPublic& other)
: displayName (other.displayName)
, externalUrls (other.externalUrls)
, followers (other.followers)
, href (other.href)
, id (other.id)
, images (other.images)
, type (other.type)
, uri (other.uri)
{}

const String& UserPublic::GetDisplayName() const
{
    return displayName;
}

const StringPairArray& UserPublic::GetExternalUrls() const
{
    return externalUrls;
}

const Followers& UserPublic::GetFollowers() const
{
    return followers;
}

const String& UserPublic::GetHref() const
{
    return href;
}

const String& UserPublic::GetId() const
{
    return id;
}

const Array<spotify::Image>& UserPublic::GetImages() const
{
    return images;
}

const String& UserPublic::GetType() const
{
    return type;
}

const String& UserPublic::GetUri() const
{
    return uri;
}

}
