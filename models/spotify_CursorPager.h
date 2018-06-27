namespace spotify {

template <class T> class CursorPager
{
public:
    CursorPager<T>();
    CursorPager<T> (const juce::var& pagerJson);
    CursorPager<T> (const CursorPager<T>& other);
    
    const juce::String& GetHref() const;
    const juce::Array<T>& GetItems() const;
    int GetLimit() const;
    const juce::String& GetNext() const;
    Cursor GetCursors() const;
    int GetTotal() const;

private:
    juce::String href;
    juce::Array<T> items;
    int limit;
    juce::String next;
    Cursor cursors;
    int total;
};

template <typename T> CursorPager<T>::CursorPager() = default;

template <typename T> CursorPager<T>::CursorPager(const juce::var& pagerJson)
: cursors (pagerJson["cursors"])
{
    href = pagerJson["href"].toString();
    limit = pagerJson["limit"];
    total = pagerJson["total"];

    for (auto json : * pagerJson["items"].getArray()) {
        items.add (T(json));
    }

    if(!pagerJson["next"].isVoid()) {
        next = pagerJson["next"].toString();
    }
}
    
template <typename T> CursorPager<T>::CursorPager(const CursorPager<T>& other)
: href (other.href)
, items (other.items)
, limit (other.limit)
, next (other.next)
, cursors (other.cursors)
, total (other.total)
{}

template <typename T> const juce::String& CursorPager<T>::GetHref() const
{
    return href;
}

template <typename T> const juce::Array<T>& CursorPager<T>::GetItems() const
{
    return items;
}

template <typename T> int CursorPager<T>::GetLimit() const
{
    return limit;
}

template <typename T> const juce::String& CursorPager<T>::GetNext() const
{
    return next;
}

template <typename T> Cursor CursorPager<T>::GetCursors() const
{
    return cursors;
}

template <typename T> int CursorPager<T>::GetTotal() const
{
    return total;
}

}
