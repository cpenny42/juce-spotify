namespace spotify {

Error::Error(const var& pagerJson)
{
    status = pagerJson["status"];
    message = pagerJson["message"].toString();
}
    
Error::Error (const Error& other)
: status (other.status)
, message (other.message)
{}

int Error::GetStatus() const
{
    return status;
}

const String& Error::GetMessage() const
{
    return message;
}

}
