namespace spotify {

Recommendations::Recommendations(const var& reccomendationsJson)
{
    for (auto json : * reccomendationsJson["seeds"].getArray()) {
        seeds.add (RecommendationsSeed (json));
    }
    
    for (auto json : * reccomendationsJson["tracks"].getArray()) {
        tracks.add (Track (json));
    }
}
    
Recommendations::Recommendations (const Recommendations& other)
: seeds (other.seeds)
, tracks (other.tracks)
{}

const Array<RecommendationsSeed>& Recommendations::GetSeeds() const
{
    return seeds;
}

const Array<Track>& Recommendations::GetTracks() const
{
    return tracks;
}

}
