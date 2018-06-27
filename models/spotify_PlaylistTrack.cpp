namespace spotify {

PlaylistTrack::PlaylistTrack(const var& trackJson)
: addedBy (trackJson["added_by"])
, track (trackJson["track"])
{
    addedAt = trackJson["added_at"].toString();
    isLocal = trackJson["is_local"];
}
    
PlaylistTrack::PlaylistTrack (const PlaylistTrack& other)
: addedAt (other.addedAt)
, addedBy (other.addedBy)
, isLocal (other.isLocal)
, track (other.track)
{}

const String& PlaylistTrack::GetAddedAt() const
{
    return addedAt;
}

const UserPublic& PlaylistTrack::GetAddedBy() const
{
    return addedBy;
}

bool PlaylistTrack::IsLocal() const
{
    return isLocal;
}

const Track& PlaylistTrack::GetTrack() const
{
    return track;
}

}
