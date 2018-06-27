namespace spotify {

User::User(const var& userJson) : UserPublic::UserPublic(userJson)
{
    birthdate = userJson["birthdate"].toString();
    country = userJson["country"].toString();
    email = userJson["email"].toString();
    product = userJson["product"].toString();
}

User::User (const User& other)
: UserPublic (other)
, birthdate (other.birthdate)
, country (other.country)
, email (other.email)
, product (other.product)
{}
    
const String& User::GetBirthdate() const
{
    return birthdate;
}

const String& User::GetCountry() const
{
    return country;
}

const String& User::GetEmail() const
{
    return email;
}

const String& User::GetProduct() const
{
    return product;
}

}
