
namespace spotify
{
    class WebAPI    :   public juce::DeletedAtShutdown, public juce::ChangeBroadcaster
    {
    public:
        
        juce_DeclareSingleton(WebAPI, false)
        
        WebAPI();
        ~WebAPI();
        
        static void connect();
        static void addConnectionListener (juce::ChangeListener* listener);
        static bool isConnected();
        
        static void setAuthToken(juce::String authToken);
        static void setAuthStorageParameters (const juce::PropertiesFile::Options& options);
        
        static Album getAlbum(juce::String albumId, juce::StringPairArray options = juce::StringPairArray());
        
        static Pager<Track> searchTracks(juce::String query, juce::StringPairArray options = juce::StringPairArray());
        
        static juce::String searchTracksRaw(juce::String query, juce::StringPairArray options = juce::StringPairArray());

        static void play(const juce::String& uri = "", juce::StringPairArray options = juce::StringPairArray());
        static void pause(const juce::String& uri = "", juce::StringPairArray options = juce::StringPairArray());

        static CurrentlyPlayingTrack getMyCurrentPlayingTrack(juce::StringPairArray options = juce::StringPairArray());

        static AudioFeatures getAudioFeatures(juce::String trackId, juce::StringPairArray options = juce::StringPairArray());

        
//        Array<Album> GetAlbums(StringArray albumIds, StringPairArray options = StringPairArray());
//
//        Pager<TrackSimple> GetAlbumTracks(String albumId, StringPairArray options = StringPairArray());
//
//        Artist GetArtist(String artistId, StringPairArray options = StringPairArray());
//
//        Array<Artist> GetArtists(StringArray artistIds, StringPairArray options = StringPairArray());
//
//        Pager<AlbumSimple> GetArtistAlbums(String artistId, StringPairArray options = StringPairArray());
//
//        Array<Track> GetArtistTopTracks(String artistId, String country, StringPairArray options = StringPairArray());
//
//        Array<Artist> GetArtistRelatedArtists(String artistId, StringPairArray options = StringPairArray());
//
//
//        Array<AudioFeatures> GetAudioFeatures(StringArray trackIds, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistSimple> GetFeaturedPlaylists(StringPairArray options = StringPairArray());
//
//        Pager<AlbumSimple> GetNewReleases(StringPairArray options = StringPairArray());
//
//        Pager<Category> GetCategories(StringPairArray options = StringPairArray());
//
//        Category GetCategory(String categoryId, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistSimple> GetCategoryPlaylists(String categoryId, StringPairArray options = StringPairArray());
//
//        User GetMe(StringPairArray options = StringPairArray());
//
//        CursorPager<Artist> GetMyFollowedArtists(StringPairArray options = StringPairArray());
//
//        void FollowArtist(String artistId, StringPairArray options = StringPairArray());
//
//        void FollowUser(String userId, StringPairArray options = StringPairArray());
//
//        void UnfollowArtist(String artistId, StringPairArray options = StringPairArray());
//
//        void UnfollowUser(String userId, StringPairArray options = StringPairArray());
//
//        bool CheckFollowingArtist(String artistId, StringPairArray options = StringPairArray());
//
//        bool CheckFollowingUser(String userId, StringPairArray options = StringPairArray());
//
//        void FollowPlaylist(String ownerId, String playlistId, StringPairArray options = StringPairArray());
//
//        void UnfollowPlaylist(String ownerId, String playlistId, StringPairArray options = StringPairArray());
//
//        void SaveTracks(StringArray trackIds, StringPairArray options = StringPairArray());
//
//        Pager<SavedTrack> GetMySavedTracks(StringPairArray options = StringPairArray());
//
//        void RemoveSavedTracks(StringArray trackIds, StringPairArray options = StringPairArray());
//
//        bool CheckSavedTracks(StringArray trackIds, StringPairArray options = StringPairArray());
//
//        void SaveAlbums(StringArray albumIds, StringPairArray options = StringPairArray());
//
//        Pager<SavedAlbum> GetMySavedAlbums(StringPairArray options = StringPairArray());
//
//        void RemoveSavedAlbums(StringArray albumIds, StringPairArray options = StringPairArray());
//
//        bool CheckSavedAlbums(StringArray albumIds, StringPairArray options = StringPairArray());
//
//        Pager<Artist> GetMyTopArtists(StringPairArray options = StringPairArray());
//
//        Pager<Track> GetMyTopTracks(StringPairArray options = StringPairArray());
//
//        Recommendations GetRecommendations(StringPairArray options = StringPairArray());
//
//        Pager<AlbumSimple> SearchAlbums(String query, StringPairArray options = StringPairArray());
//
//        Pager<Artist> SearchArtists(String query, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistSimple> SearchPlaylists(String query, StringPairArray options = StringPairArray());
//
//
//        Track GetTrack(String trackId, StringPairArray options = StringPairArray());
//
//        Array<Track> GetTracks(StringArray trackIds, StringPairArray options = StringPairArray());
//
//        UserPublic GetUser(String userId, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistSimple> GetUserPlaylists(String userId, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistSimple> GetMyPlaylists(StringPairArray options = StringPairArray());
//
//        Playlist GetPlaylist(String userId, String playlistId, StringPairArray options = StringPairArray());
//
//        Pager<PlaylistTrack> GetPlaylistTracks(String userId, String playlistId, StringPairArray options = StringPairArray());
//
////        Playlist CreatePlaylist(String userId, String name, StringPairArray options = StringPairArray());
////
////        void EditPlaylist(String userId, String playlistId, StringPairArray options = StringPairArray());
////
////        void AddTracksToPlaylist(String userId, String playlistId, StringArray trackUris, StringPairArray options = StringPairArray());
//
////        void RemoveTracksFromPlaylist(String userId, String playlistId, StringArray trackUris, String snapshotId = "");
////
////        void RemoveTracksFromPlaylist(String userId, String playlistId, std::map<String, std::vector<int>> trackUrisToPositions, String snapshotId = "");
//
////        void RemoveTracksFromPlaylist(String userId, String playlistId, std::vector<int> positions, String snapshotId);
//
////        void ReorderPlaylistTracks(String userId, String playlistId, int rangeStart, int insertBefore, StringPairArray options = StringPairArray());
//
////        void ReplacePlaylistTracks(String userId, String playlistId, StringArray trackUris, StringPairArray options = StringPairArray());
//
////        bool CheckUserFollowingPlaylist(String userId, String playlistId, StringArray userIds, StringPairArray options = StringPairArray());
//
//        void UploadCustomPlaylistCover(String userId, String playlistId, String contentType, String image, StringPairArray options = StringPairArray());
//
//        CursorPager<PlayHistoryObject> GetMyRecentlyPlayed(StringPairArray options = StringPairArray());
//
//        Array<Device> GetMyDevices(StringPairArray options = StringPairArray());
//
//        CurrentlyPlayingContext GetMyCurrentPlayback(StringPairArray options = StringPairArray());
//
//
//        void TransferMyPlayback(String deviceId, StringPairArray options = StringPairArray());
//
//        void Resume(StringPairArray options = StringPairArray());
//
//
//        void SkipToNext(StringPairArray options = StringPairArray());
//
//        void SkipToPrevious(StringPairArray options = StringPairArray());
//
//        void SetRepeat(String state, StringPairArray options = StringPairArray());
//
//        void SetVolume(int volumePercent, StringPairArray options = StringPairArray());
//
//        void ToggleShuffle(bool state, StringPairArray options = StringPairArray());
        
    private:
        bool isCurrentlyConnected;
        juce::String authToken;
        juce::ApplicationProperties properties;
        
        friend class spotify::AuthenticationServer;
        
        juce::PropertiesFile::Options createDefaultOptions();
    };
    
    
    class SongSearchComponent   :   public juce::Component,
                                    public juce::TextEditor::Listener,
                                    public juce::ActionListener,
                                    public juce::ChangeBroadcaster
    {
    public:
        SongSearchComponent()
        : pool ()
        {
            addAndMakeVisible(& searchEditor);
            searchEditor.addListener (this);
        }
        
        void textEditorReturnKeyPressed (juce::TextEditor& editor) override
        {
#if JUCE_MODAL_LOOPS_PERMITTED
            if (&editor == &searchEditor) {
                addJob();
            }
#endif
        }
        
        void textEditorTextChanged (juce::TextEditor& editor) override
        {
#if JUCE_MODAL_LOOPS_PERMITTED
            if (&editor == &searchEditor) {
                addJob();
            }
#endif
        }
        
        void textEditorEscapeKeyPressed (juce::TextEditor& editor) override
        {
#if JUCE_MODAL_LOOPS_PERMITTED
            juce::PopupMenu::dismissAllActiveMenus();
#endif
        }
        
        void paint (juce::Graphics& g) override
        {
            g.fillAll (juce::Colours::beige);
        }
        
        void resized() override
        {
            searchEditor.setBounds (getLocalBounds());
            searchEditor.setFont(searchEditor.getFont().withHeight(getHeight() * 0.6f));
        }
        
        void actionListenerCallback (const juce::String& message) override
        {
#if JUCE_MODAL_LOOPS_PERMITTED
            tracksPager = spotify::Pager<spotify::Track> (juce::JSON::fromString(message)["tracks"]);
            refreshTracks();
#endif
        }
        
        spotify::Track getSelectedTrack()
        {
            return selectedTrack;
        }
        
    private:
        
        void addJob()
        {
            if (searchEditor.getText().isNotEmpty()) {
                pool.addJob (new SongSearchJob (this, "", searchEditor.getText()), true);
            }
        }
        
        void refreshTracks()
        {
#if JUCE_MODAL_LOOPS_PERMITTED
            juce::PopupMenu::dismissAllActiveMenus();
            juce::PopupMenu popup;
            const juce::Array<spotify::Track>& tracks = tracksPager.GetItems();

            for (int i = 0; i < tracks.size(); i++) {
                popup.addCustomItem(i + 1, new SongComponent (tracks[i]));
            }
            int result = popup.showAt(& searchEditor, 0, 0, 0, 0, nullptr);
            if (result > 0) {
                selectedTrack = tracksPager.GetItems()[result - 1];
                sendChangeMessage();
            }
            searchEditor.grabKeyboardFocus();
#endif
        }
        
        class SongSearchJob :   public juce::ThreadPoolJob, public juce::ActionBroadcaster
        {
        public:
            
            SongSearchJob (juce::ActionListener* listener, const juce::String& name, const juce::String query)
            :   ThreadPoolJob (name), parent (listener), q (query)
            {
                addActionListener(listener);
            }
            
            ~SongSearchJob()
            {
                removeActionListener(parent);
            }
            
            juce::ThreadPoolJob::JobStatus runJob() override
            {
                juce::StringPairArray options;
                options.set("limit", "10");
                
                const juce::String res = spotify::WebAPI::searchTracksRaw (q, options);
                sendActionMessage (res);
                juce::Thread::sleep(1);
                return juce::ThreadPoolJob::JobStatus::jobHasFinished;
            }
            
        private:
            juce::ActionListener* parent;
            const juce::String q;
        };
        
        class SongComponent :   public juce::PopupMenu::CustomComponent
        {
        public:
            
            SongComponent(spotify::Track song)  :   track (song), width (400)
            {
            }
            
            void getIdealSize (int& idealWidth, int& idealHeight) override
            {
                idealWidth = width;
                idealHeight = 40;
            }
            
            void paint (juce::Graphics& g) override
            {
                g.fillAll (juce::Colours::black.withAlpha (0.2f));
                
                if (isItemHighlighted()) {
                    g.fillAll (juce::Colours::white.withAlpha (0.1f));
                }
                
                const juce::String songName = track.GetName();
                const juce::String artistName = track.GetArtists()[0].GetName() + "  -  " + track.GetAlbum().GetName();
                
                g.setColour (juce::Colours::grey);
                g.drawRect (0, 0, getWidth(), getHeight());
                g.setFont (getHeight() * 0.4f);
                g.setColour (juce::Colours::white);
                g.drawText (songName, 5, 8,
                            g.getCurrentFont().getStringWidth (songName) + 10,
                            proportionOfHeight(0.5f) - 10,
                            juce::Justification::centredLeft);
                int songWidth = g.getCurrentFont().getStringWidth (songName);
                
                g.setFont (getHeight() * 0.35f);
                g.drawText (artistName, 5, proportionOfHeight(0.5f)  + 5,
                            g.getCurrentFont().getStringWidth (artistName),
                            proportionOfHeight(0.5f) - 10,
                            juce::Justification::centredLeft);
                int artistWidth = g.getCurrentFont().getStringWidth (artistName);
                
                width = juce::jmax(songWidth, artistWidth);
            }
            
        private:
            
            juce::ScopedPointer<juce::InputStream> inStream;
            juce::MemoryBlock imageData;
            spotify::Track track;
            spotify::Image albumArt;
            int width;
        };
        
        juce::TextEditor searchEditor;
        spotify::Pager<spotify::Track> tracksPager;
        juce::ThreadPool pool;
        
        spotify::Track selectedTrack;
    };
}
