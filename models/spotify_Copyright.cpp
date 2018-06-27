namespace spotify {

Copyright::Copyright(const var& copyrightJson)
{
    text = copyrightJson["text"].toString();
    type = copyrightJson["type"].toString();
}
    
Copyright::Copyright (const Copyright& other)
: text (other.text)
, type (other.type)
{}

const String& Copyright::GetText() const
{
    return text;
}

const String& Copyright::GetType() const
{
    return type;
}

}
