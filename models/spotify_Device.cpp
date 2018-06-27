namespace spotify {
    
Device::Device(const var& deviceJson)
{
    if (! deviceJson["id"].isVoid()) {
        id = deviceJson["id"].toString();
    }
    isActive = deviceJson["is_active"];
    isRestricted = deviceJson["is_restricted"];
    name = deviceJson["name"].toString();
    type = deviceJson["type"].toString();
    if (! deviceJson["volume_percent"].isVoid()) {
        volumePercent = deviceJson["volume_percent"];
    }
}
    
Device::Device (const Device& other)
: id (other.id)
, isActive (other.isActive)
, isRestricted (other.isRestricted)
, name (other.name)
, type (other.type)
, volumePercent (other.volumePercent)
{}

const String& Device::GetId() const
{
    return id;
}

bool Device::IsActive() const
{
    return isActive;
}

bool Device::IsRestricted() const
{
    return isRestricted;
}

const String& Device::GetName() const
{
    return name;
}

const String& Device::GetType() const
{
    return type;
}

int Device::GetVolumePercent() const
{
    return volumePercent;
}
    
}
