
namespace spotify
{
    //==============================================================================
    //==============================================================================
    class AuthenticationBrowser :   public juce::WebBrowserComponent,
                                    public juce::ChangeBroadcaster
    {
    public:
        AuthenticationBrowser(juce::ChangeListener* listener);
        ~AuthenticationBrowser();
        bool pageAboutToLoad(const juce::String& newURL) override;
    };
    
    //==============================================================================
    //==============================================================================
    class AuthenticationWindow    : public juce::DocumentWindow,
                                    public juce::ChangeBroadcaster,
                                    private juce::ChangeListener
    {
    public:
        AuthenticationWindow (juce::ChangeListener* listener);
        ~AuthenticationWindow();
        
        void closeButtonPressed() override;
        AuthenticationBrowser& getBrowser();
        void changeListenerCallback (juce::ChangeBroadcaster* source) override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AuthenticationWindow)
    };
    
    //==============================================================================
    //==============================================================================
    class AuthenticationServer :    public Mongoose::WebController,
                                    private juce::ChangeListener,
                                    private juce::Thread,
                                    private juce::AsyncUpdater,
                                    private juce::DeletedAtShutdown
    {
    public:
        
        juce_DeclareSingleton(AuthenticationServer, false)
        
        AuthenticationServer();
        ~AuthenticationServer();
        
        static void start();
        
        void main  (Mongoose::Request &request, Mongoose::StreamResponse &response);
        void login (Mongoose::Request &request, Mongoose::StreamResponse &response);
        void callback (Mongoose::Request &request, Mongoose::StreamResponse &response);
        void done (Mongoose::Request &request, Mongoose::StreamResponse &response);

        void showAuthWindow();
        
        const juce::String getBaseUrl();
        
    private:
        
        void setupRoutes();
        juce::PropertiesFile& getProperties();
        void changeListenerCallback (juce::ChangeBroadcaster* source) override;
        void run() override;
        void handleAsyncUpdate() override;
        
        const unsigned int port;
        Mongoose::Server server;
        juce::String scope;
        juce::String baseUrl;
        juce::String redirectUri;
        juce::String sessionId;
        
        const juce::String refreshTokenKey;
        
        juce::ScopedPointer<AuthenticationWindow> authenticationWindow;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AuthenticationServer)
    };
    
}
