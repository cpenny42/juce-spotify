namespace spotify {

Followers::Followers(const var& followersJson)
{
    /* href currently always null, as the Web API doesn't yet support it */
    if(!followersJson["href"].isVoid()) {
        href = followersJson["href"].toString();
    }
    if(followersJson["total"].isVoid()) {
        total = 0;
    }
    else {
        total = followersJson["total"];
    }
}
    
Followers::Followers (const Followers& other)
: href (other.href)
, total (other.total)
{}

const String& Followers::GetHref() const
{
    return href;
}

int Followers::GetTotal() const
{
    return total;
}

}
