namespace spotify {
    
template <class T> class Pager
{
public:
    Pager<T>();
    Pager<T>(const juce::var& pagerJson);
    Pager<T>(const Pager<T>& other);

    const juce::String& GetHref() const;
    const juce::Array<T>& GetItems() const;
    int GetLimit() const;
    const juce::String& GetNext() const;
    int GetOffset() const;
    const juce::String& GetPrevious() const;
    int GetTotal() const;

private:
    juce::String href;
    juce::Array<T> items;
    int limit;
    juce::String next;
    int offset;
    juce::String previous;
    int total;
};

template <typename T> Pager<T>::Pager() = default;

template <typename T> Pager<T>::Pager(const juce::var& pagerJson)
{
    if (!pagerJson["href"].isVoid()) {
        href = pagerJson["href"].toString();
    }
    if(!pagerJson["limit"].isVoid()) {
        limit = pagerJson["limit"];
    }
    if (!pagerJson["next"].isVoid()) {
        next = pagerJson["next"].toString();
    }
    if (!pagerJson["offset"].isVoid()) {
        offset = pagerJson["offset"];
    }
    if (!pagerJson["previous"].isVoid()) {
        previous = pagerJson["previous"].toString();
    }
    total = pagerJson["total"];
    if (! pagerJson["items"].isArray()) {
        return;
    }
    for (auto json : * pagerJson["items"].getArray()) {
        items.add (T (json));
    }
}
    
template <typename T> Pager<T>::Pager(const Pager<T>& other)
{
    href = other.href;
    items = other.items;
    limit = other.limit;
    next = other.next;
    offset = other.offset;
    previous = other.previous;
    total = other.total;
}

template <typename T> const juce::String& Pager<T>::GetHref() const
{
    return href;
}

template <typename T> const juce::Array<T>& Pager<T>::GetItems() const
{
    return items;
}

template <typename T> int Pager<T>::GetLimit() const
{
    return limit;
}

template <typename T> const juce::String& Pager<T>::GetNext() const
{
    return next;
}

template <typename T> int Pager<T>::GetOffset() const
{
    return offset;
}

template <typename T> const juce::String& Pager<T>::GetPrevious() const
{
    return previous;
}

template <typename T> int Pager<T>::GetTotal() const
{
    return total;
}
    
}
