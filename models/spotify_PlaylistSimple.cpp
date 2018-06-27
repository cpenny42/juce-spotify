namespace spotify {

PlaylistSimple::PlaylistSimple(const var& playlistJson)
: tracks (playlistJson["tracks"])
, owner (playlistJson["owner"])
{
    isCollaborative = playlistJson["collaborative"];
    href = playlistJson["href"].toString();
    id = playlistJson["id"].toString();
    name = playlistJson["name"].toString();
    snapshotId = playlistJson["snapshot_id"].toString();
    type = playlistJson["type"];
    uri = playlistJson["uri"];
    
    isPublic = playlistJson["public"].isVoid() ? false : playlistJson["public"].operator bool();
    
    for (auto namedValue : playlistJson["external_urls"].getDynamicObject()->getProperties()) {
        externalUrls.set(namedValue.name.toString(), namedValue.value.toString());
    }
    for (auto json : * playlistJson["images"].getArray()) {
        images.add (spotify::Image (json));
    }
}
    
PlaylistSimple::PlaylistSimple (const PlaylistSimple& other)
: isCollaborative (other.isCollaborative)
, href (other.href)
, id (other.id)
, name (other.name)
, isPublic (other.isPublic)
, snapshotId (other.snapshotId)
, tracks (other.tracks)
, type (other.type)
, uri (other.uri)
, images (other.images)
, externalUrls (other.externalUrls)
, owner (other.owner)
{}

bool PlaylistSimple::IsCollaborative() const
{
    return isCollaborative;
}

const StringPairArray& PlaylistSimple::GetExternalUrls() const
{
    return externalUrls;
}

const String& PlaylistSimple::GetHref() const
{
    return href;
}

const String& PlaylistSimple::GetId() const
{
    return id;
}

const Array<spotify::Image>& PlaylistSimple::GetImages() const
{
    return images;
}

const String& PlaylistSimple::GetName() const
{
    return name;
}

const UserPublic& PlaylistSimple::GetOwner() const
{
    return owner;
}

bool PlaylistSimple::IsPublic() const
{
    return isPublic;
}

const String& PlaylistSimple::GetSnapshotId() const
{
    return snapshotId;
}

const Pager<PlaylistTrack>& PlaylistSimple::GetTracks() const
{
    return tracks;
}

const String& PlaylistSimple::GetType() const
{
    return type;
}

const String& PlaylistSimple::GetUri() const
{
    return uri;
}
    
}
