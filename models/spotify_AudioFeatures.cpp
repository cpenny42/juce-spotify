namespace spotify {

AudioFeatures::AudioFeatures(const var& audioFeaturesJson)
{
    acousticness = audioFeaturesJson["acousticness"];
    analysisUrl = audioFeaturesJson["analysis_url"].toString();
    danceability = audioFeaturesJson["danceability"];
    durationMs = audioFeaturesJson["duration_ms"];
    energy = audioFeaturesJson["energy"];
    id = audioFeaturesJson["id"].toString();
    instrumentalness = audioFeaturesJson["instrumentalness"];
    key = audioFeaturesJson["key"];
    liveness = audioFeaturesJson["liveness"];
    loudness = audioFeaturesJson["loudness"];
    mode = audioFeaturesJson["mode"];
    speechiness = audioFeaturesJson["speechiness"];
    tempo = audioFeaturesJson["tempo"];
    timeSignature = audioFeaturesJson["time_signature"];
    trackHref = audioFeaturesJson["track_href"].toString();
    type = audioFeaturesJson["type"].toString();
    uri = audioFeaturesJson["uri"].toString();
    valence = audioFeaturesJson["valence"];
}
    
AudioFeatures::AudioFeatures (const AudioFeatures& other)
: acousticness (other.acousticness)
, analysisUrl (other.analysisUrl)
, danceability (other.danceability)
, durationMs (other.durationMs)
, energy (other.energy)
, id (other.id)
, instrumentalness (other.instrumentalness)
, key (other.key)
, liveness (other.liveness)
, loudness (other.loudness)
, mode (other.mode)
, speechiness (other.speechiness)
, tempo (other.tempo)
, timeSignature (other.timeSignature)
, trackHref (other.trackHref)
, type (other.type)
, uri (other.uri)
, valence (other.valence)
{}

float AudioFeatures::GetAcousticness() const
{
    return acousticness;
}

const String& AudioFeatures::GetAnalysisUrl() const
{
    return analysisUrl;
}

float AudioFeatures::GetDanceability() const
{
    return danceability;
}

int AudioFeatures::GetDurationMs() const
{
    return durationMs;
}

float AudioFeatures::GetEnergy() const
{
    return energy;
}

const String& AudioFeatures::GetId() const
{
    return id;
}

float AudioFeatures::GetInstrumentalness() const
{
    return instrumentalness;
}

int AudioFeatures::GetKey() const
{
    return key;
}

float AudioFeatures::GetLiveness() const
{
    return liveness;
}

float AudioFeatures::GetLoudness() const
{
    return loudness;
}

int AudioFeatures::GetMode() const
{
    return mode;
}

float AudioFeatures::GetSpeechiness() const
{
    return speechiness;
}

float AudioFeatures::GetTempo() const
{
    return tempo;
}

int AudioFeatures::GetTimeSignature() const
{
    return timeSignature;
}

const String& AudioFeatures::GetTrackHref() const
{
    return trackHref;
}

const String& AudioFeatures::GetType() const
{
    return type;
}

const String& AudioFeatures::GetUri() const
{
    return uri;
}

float AudioFeatures::GetValence() const
{
    return valence;
}

bool AudioFeatures::isMajorKey() const
{
    return mode == 1;
}
    
}
