namespace spotify {
    
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
AuthenticationBrowser::AuthenticationBrowser(juce::ChangeListener* listener)
{
    addChangeListener(listener);
    goToURL(AuthenticationServer::getInstance()->getBaseUrl() + "/login");
}
    
AuthenticationBrowser::~AuthenticationBrowser()
{
    removeAllChangeListeners();
}

bool AuthenticationBrowser::pageAboutToLoad(const juce::String& newURL)
{
    if (newURL.endsWith ("/done")) {
        sendChangeMessage();
        return false;
    }
    else {
        return true;
    }
}
    
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
AuthenticationWindow::AuthenticationWindow (juce::ChangeListener* listener)
: juce::DocumentWindow (TRANS("Log in to Spotify..."),
                        juce::Desktop::getInstance().getDefaultLookAndFeel()
                            .findColour (juce::ResizableWindow::backgroundColourId),
                        juce::DocumentWindow::allButtons)
{
    addChangeListener (listener);
    
    setUsingNativeTitleBar (true);
    auto* b = new AuthenticationBrowser (this);
    b->setSize(600, 600);
    setContentOwned (b, true);
    
    centreWithSize (getWidth(), getHeight());
    setVisible (true);
    setResizable(true, true);
}
    
AuthenticationWindow::~AuthenticationWindow()
{
    removeAllChangeListeners();
}
    
void AuthenticationWindow::closeButtonPressed()
{
    sendChangeMessage();
}
    
AuthenticationBrowser& AuthenticationWindow::getBrowser()
{
    return * dynamic_cast<AuthenticationBrowser*>(getContentComponent());
}
    
void AuthenticationWindow::changeListenerCallback (juce::ChangeBroadcaster* source)
{
    sendChangeMessage();
}
    
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================

#ifndef SPOTIFY_AUTHSERVER_PORT
#define SPOTIFY_AUTHSERVER_PORT 8888
#endif
    
juce_ImplementSingleton(AuthenticationServer);
    
void AuthenticationServer::start()
{
    (void) getInstance();
}
    
AuthenticationServer::AuthenticationServer()
: Thread ("spotify::AuthenticationServer")
, port (SPOTIFY_AUTHSERVER_PORT)
, server ((int) port)
, scope ("user-read-private user-read-email playlist-read-private playlist-read-collaborative playlist-modify-public playlist-modify-private user-follow-modify user-follow-read user-library-read user-library-modify user-read-private user-read-birthdate user-read-email user-top-read ugc-image-upload user-read-playback-state user-modify-playback-state user-read-currently-playing user-read-recently-played")
, baseUrl ("http://localhost:" + String(SPOTIFY_AUTHSERVER_PORT))
, redirectUri (baseUrl + "/callback")
, sessionId (String(Random::getSystemRandom().nextInt64()))
, refreshTokenKey ("spotify::AuthenticationServer::refresh_token")
{
    setupRoutes();
    server.registerController(this);
    server.start();
    
    startThread();
}
    
AuthenticationServer::~AuthenticationServer()
{
    clearSingletonInstance();
}
    
void AuthenticationServer::main (Mongoose::Request &req,
                                 Mongoose::StreamResponse &res)
{
    res <<
    "<!doctype html>\n"
    "<html>\n"
    "<head>\n"
    "\t<title>Log In to Spotify</title>\n"
    "\t<link rel=\"stylesheet\" href=\"//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css\">\n"
    "</head>\n"
    "<body>\n"
    "\t<div class=\"container\">\n"
    "\t\t<div id=\"login\">\n"
    "\t\t\t<a href=\"/login\" class=\"btn btn-primary\">Log in with Spotify</a>\n"
    "\t\t</div>\n"
    "\t</div>\n"
    "</body>\n"
    "</html>";
}

void AuthenticationServer::login (Mongoose::Request &req,
                                  Mongoose::StreamResponse &res)
{
    String requestAuthenticationUrl (
        "https://accounts.spotify.com/authorize?"
            "client_id=" + String(SPOTIFY_CLIENT_ID) + "&"
            "response_type=code&"
            "redirect_uri=" + redirectUri + "&"
            "state=" + sessionId + "&"
            "scope=" + scope + "&"
            "show_dialog=false"
    );
    
    res <<
    "<!doctype html>\n"
    "<html>\n"
    "<head>\n"
    "    <title>Redirecting to Spotify...</title>\n"
    "    <meta http-equiv=\"refresh\" content=\"0; url=" + requestAuthenticationUrl + "\">\n"
    "</head>\n"
    "<body>\n"
    "</body>\n"
    "</html>";
}

void AuthenticationServer::callback (Mongoose::Request &req,
                                     Mongoose::StreamResponse &res)
{
    if (req.hasVariable("error")) {
        const String error = req.get("error");
        res << "error: " << error << "\n";
    }
    else {
        const String code = req.get("code");
        const String state = req.get("state");
        const bool hasValidRefreshToken = getProperties().containsKey(refreshTokenKey) &&
                                          getProperties().getValue(refreshTokenKey).isNotEmpty();
        
        URL tokenUrl = hasValidRefreshToken
        
            // Use Refresh Token
            ? URL("https://accounts.spotify.com/api/token")
                    .withParameter("grant_type", "refresh_token")
                    .withParameter("refresh_token", getProperties().getValue(refreshTokenKey))
                    .withParameter("redirect_uri", redirectUri)
                    .withParameter("client_id", SPOTIFY_CLIENT_ID)
                    .withParameter("client_secret", SPOTIFY_CLIENT_SECRET)
        
            // Use Authorization Code
            : URL("https://accounts.spotify.com/api/token")
                    .withParameter("grant_type", "authorization_code")
                    .withParameter("code", code)
                    .withParameter("redirect_uri", redirectUri)
                    .withParameter("client_id", SPOTIFY_CLIENT_ID)
                    .withParameter("client_secret", SPOTIFY_CLIENT_SECRET);
        
        String tokenRes = tokenUrl.readEntireTextStream(true);
        var json = JSON::fromString (tokenRes);
        
        // Error - try again using authorization code
        if (! json["error"].isVoid()) {
            URL fallbackUrl = URL("https://accounts.spotify.com/api/token")
                                .withParameter("grant_type", "authorization_code")
                                .withParameter("code", code)
                                .withParameter("redirect_uri", redirectUri)
                                .withParameter("client_id", SPOTIFY_CLIENT_ID)
                                .withParameter("client_secret", SPOTIFY_CLIENT_SECRET);
            tokenRes = fallbackUrl.readEntireTextStream(true);
            json = JSON::fromString (tokenRes);
        }

        // Store new refresh_token if we get it
        if (! json["refresh_token"].isVoid()) {
            getProperties().setValue (refreshTokenKey, json["refresh_token"].toString());
            getProperties().save();
        }
        
        // WebAPI can now make requests
        WebAPI::setAuthToken(json["access_token"].toString());
        
        res <<
        "<!doctype html>\n"
        "<html>\n"
        "<head>\n"
        "    <title>Redirecting</title>\n"
        "    <meta http-equiv=\"refresh\" content=\"0; url=/done\">\n"
        "</head>\n"
        "<body>\n"
        "</body>\n"
        "</html>";
    }
}
    
void AuthenticationServer::done (Mongoose::Request &req,
                                 Mongoose::StreamResponse &res)
{

}
    
void AuthenticationServer::showAuthWindow()
{
    authenticationWindow = new AuthenticationWindow (this);
    authenticationWindow->getBrowser().goToURL(baseUrl + "/login");
}
    
const String AuthenticationServer::getBaseUrl()
{
    return baseUrl;
}
    
void AuthenticationServer::setupRoutes()
{
    addRoute("GET", "/", AuthenticationServer, main);
    addRoute("GET", "/login", AuthenticationServer, login);
    addRoute("GET", "/callback", AuthenticationServer, callback);
    addRoute("GET", "/done", AuthenticationServer, done);
}

PropertiesFile& AuthenticationServer::getProperties()
{
    return * WebAPI::getInstance()->properties.getUserSettings();
}

    void AuthenticationServer::changeListenerCallback(ChangeBroadcaster* source)
    {
        authenticationWindow = nullptr;
    }
    
    void AuthenticationServer::run()
    {
        const bool hasValidRefreshToken = getProperties().containsKey(refreshTokenKey) &&
                                          getProperties().getValue(refreshTokenKey).isNotEmpty();

        if (hasValidRefreshToken) {
            URL url = URL("https://accounts.spotify.com/api/token")
                .withParameter("grant_type", "refresh_token")
                .withParameter("refresh_token", getProperties().getValue(refreshTokenKey))
                .withParameter("redirect_uri", redirectUri)
                .withParameter("client_id", SPOTIFY_CLIENT_ID)
                .withParameter("client_secret", SPOTIFY_CLIENT_SECRET);
            
            String response = url.readEntireTextStream(true);
            var res = JSON::fromString (response);
            
            // Store new refresh_token if we get it
            if (! res["refresh_token"].isVoid()) {
                getProperties().setValue (refreshTokenKey, res["refresh_token"].toString());
                getProperties().save();
            }
            
            // WebAPI can now make requests
            WebAPI::setAuthToken(res["access_token"].toString());
        }
        else {
            WebAPI::getInstance()->sendChangeMessage();
        }
    }
    
    void AuthenticationServer::handleAsyncUpdate()
    {
        showAuthWindow();
    }
}
