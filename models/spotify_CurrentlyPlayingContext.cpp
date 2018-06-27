namespace spotify {

CurrentlyPlayingContext::CurrentlyPlayingContext(const var& currentlyPlayingJson)
: device (currentlyPlayingJson["device"])
, context (currentlyPlayingJson["context"])
, item (currentlyPlayingJson["item"])
{
    repeatState = currentlyPlayingJson["repeat_state"].toString();
    shuffleState = currentlyPlayingJson["shuffle_state"];
    timestamp = currentlyPlayingJson["timestamp"];
    progressMs = currentlyPlayingJson["progress_ms"];
    isPlaying = currentlyPlayingJson["is_playing"];
}
    
CurrentlyPlayingContext::CurrentlyPlayingContext (const CurrentlyPlayingContext& other)
: repeatState (other.repeatState)
, shuffleState (other.shuffleState)
, timestamp (other.timestamp)
, progressMs (other.progressMs)
, isPlaying (other.isPlaying)
, device (other.device)
, context (other.context)
, item (other.item)
{}

const String& CurrentlyPlayingContext::GetRepeatState() const
{
    return repeatState;
}

bool CurrentlyPlayingContext::GetShuffleState() const
{
    return shuffleState;
}

int CurrentlyPlayingContext::GetTimestamp() const
{
    return timestamp;
}

int CurrentlyPlayingContext::GetProgressMs() const
{
    return progressMs;
}

bool CurrentlyPlayingContext::IsPlaying() const
{
    return isPlaying;
}

const Device& CurrentlyPlayingContext::GetDevice() const
{
    return device;
}
    
const Context& CurrentlyPlayingContext::GetContext() const
{
    return context;
}

const Track& CurrentlyPlayingContext::GetItem() const
{
    return item;
}

}
