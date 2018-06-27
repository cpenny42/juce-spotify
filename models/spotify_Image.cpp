namespace spotify {

Image::Image(const var& imageJson)
{
    if(!imageJson["height"].isVoid()) {
        height = imageJson["height"];
    }
    if(!imageJson["width"].isVoid()) {
        width = imageJson["width"];
    }
    url = imageJson["url"].toString();
}
    
Image::Image (const Image& other)
: url (other.url)
, height (other.height)
, width (other.width)
{}

const String& Image::GetUrl() const
{
    return url;
}

int Image::GetHeight() const
{
    return height;
}

int Image::GetWidth() const
{
    return width;
}

}
