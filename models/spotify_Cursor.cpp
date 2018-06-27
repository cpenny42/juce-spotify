namespace spotify {

Cursor::Cursor(const var& cursorJson)
{
    if(!cursorJson["after"].isVoid()) {
        after = cursorJson["after"].toString();
    }
}
    
Cursor::Cursor (const Cursor& other)
: after (other.after)
{}

const String& Cursor::GetAfter() const
{
    return after;
}

}
