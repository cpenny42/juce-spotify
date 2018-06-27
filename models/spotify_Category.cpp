namespace spotify {

Category::Category(const var& categoryJson)
{
    href = categoryJson["href"].toString();
    id = categoryJson["id"].toString();
    name = categoryJson["name"].toString();
    
    for (auto json : * categoryJson["icons"].getArray()) {
        icons.add (spotify::Image (json));
    }    
}
    
Category::Category (const Category& other)
: href (other.href)
, id (other.id)
, name (other.name)
, icons (other.icons)
{}

const String& Category::GetHref() const
{
    return href;
}

const String& Category::GetId() const
{
    return id;
}

const String& Category::GetName() const
{
    return name;
}
    
const Array<spotify::Image>& Category::GetIcons() const
{
    return icons;
}

}
