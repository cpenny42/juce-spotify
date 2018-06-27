namespace spotify {
    
SavedAlbum::SavedAlbum(const var& albumJson)
: album (albumJson["album"])
{
    addedAt = albumJson["added_at"].toString();
}
    
SavedAlbum::SavedAlbum (const SavedAlbum& other)
: addedAt (other.addedAt)
, album (other.album)
{}

const String& SavedAlbum::GetAddedAt() const
{
    return addedAt;
}

const Album& SavedAlbum::GetAlbum() const
{
    return album;
}

}
