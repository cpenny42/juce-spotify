namespace spotify {

Context::Context (const var& contextJson)
{
    uri = contextJson["uri"].toString();
    href = contextJson["href"].toString();
    type = contextJson["type"].toString();
    
    if (! contextJson["external_urls"].isVoid()) {
        for (auto namedValue : contextJson["external_urls"].getDynamicObject()->getProperties()) {
            externalUrls.set (namedValue.name.toString(), namedValue.value.toString());
        }
    }
}
    
Context::Context (const Context& other)
: uri (other.uri)
, href (other.href)
, type (other.type)
, externalUrls (other.externalUrls)
{}

const String& Context::GetUri() const
{
    return uri;
}

const String& Context::GetHref() const
{
    return href;
}

const String& Context::GetType() const
{
    return type;
}

const StringPairArray& Context::GetExternalUrls() const
{
    return externalUrls;
}
    
}
