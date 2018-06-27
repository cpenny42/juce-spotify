namespace spotify {

Playlist::Playlist(const var& playlistJson)
: PlaylistSimple::PlaylistSimple(playlistJson)
, followers (playlistJson["followers"])
{
    if(!playlistJson["description"].isVoid()) {
        description = playlistJson["description"].toString();
    }
}
    
Playlist::Playlist (const Playlist& other)
: PlaylistSimple (other)
, description (other.description)
, followers (other.followers)
{}

const String& Playlist::GetDescription() const
{
    return description;
}

const Followers& Playlist::GetFollowers() const
{
    return followers;
}

}
