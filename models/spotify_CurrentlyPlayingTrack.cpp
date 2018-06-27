namespace spotify {
    
CurrentlyPlayingTrack::CurrentlyPlayingTrack(const var& currentlyPlayingJson)
    : context (currentlyPlayingJson["context"])
{
    timestamp = currentlyPlayingJson["timestamp"];
    progressMs = currentlyPlayingJson["progress_ms"];
    isPlaying = currentlyPlayingJson["is_playing"];
    
    item = Track (currentlyPlayingJson["item"]);
}
    
CurrentlyPlayingTrack::CurrentlyPlayingTrack (const CurrentlyPlayingTrack& other)
: timestamp (other.timestamp)
, progressMs (other.progressMs)
, isPlaying (other.isPlaying)
, context (other.context)
, item (other.item)
{}
    
int CurrentlyPlayingTrack::GetTimestamp() const
{
    return timestamp;
}

int CurrentlyPlayingTrack::GetProgressMs() const
{
    return progressMs;
}

bool CurrentlyPlayingTrack::IsPlaying() const
{
    return isPlaying;
}

const Context& CurrentlyPlayingTrack::GetContext() const
{
    return context;
}

const Track& CurrentlyPlayingTrack::GetItem() const
{
    return item;
}
    
bool CurrentlyPlayingTrack::isValid() const
{
    return item.GetName().isNotEmpty();
}
    
}
