namespace spotify {

RecommendationsSeed::RecommendationsSeed(const var& reccomendationsJson)
{
    afterFilteringSize = reccomendationsJson["afterFilteringSize"];
    afterRelinkingSize = reccomendationsJson["afterRelinkingSize"];
    href = reccomendationsJson["href"].toString();
    id = reccomendationsJson["id"].toString();
    initialPoolSize = reccomendationsJson["initialPoolSize"];
    type = reccomendationsJson["type"].toString();
}
    
RecommendationsSeed::RecommendationsSeed (const RecommendationsSeed& other)
: afterFilteringSize (other.afterFilteringSize)
, afterRelinkingSize (other.afterRelinkingSize)
, href (other.href)
, id (other.id)
, initialPoolSize (other.initialPoolSize)
, type (other.type)
{}

int RecommendationsSeed::GetAfterFilteringSize() const
{
    return afterFilteringSize;
}

int RecommendationsSeed::GetAfterRelinkingSize() const
{
    return afterRelinkingSize;
}

const String& RecommendationsSeed::GetHref() const
{
    return href;
}

const String& RecommendationsSeed::GetId() const
{
    return id;
}

int RecommendationsSeed::GetInitialPoolSize() const
{
    return initialPoolSize;
}

const String& RecommendationsSeed::GetType() const
{
    return type;
}

}
