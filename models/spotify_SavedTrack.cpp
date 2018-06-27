namespace spotify {

SavedTrack::SavedTrack(const var& trackJson)
: track (trackJson["track"])
{
    addedAt = trackJson["added_at"].toString();
}
    
SavedTrack::SavedTrack (const SavedTrack& other)
: addedAt (other.addedAt)
, track (other.track)
{}

const String& SavedTrack::GetAddedAt() const
{
    return addedAt;
}

const Track& SavedTrack::GetTrack() const
{
    return track;
}

}
