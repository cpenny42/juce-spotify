namespace spotify {
    
juce_ImplementSingleton(WebAPI)
    
String SpotifyCurlInternal(String request, String endpoint, StringPairArray options, String authToken, String body, bool post = false)
{
    String baseUrl = "https://api.spotify.com" + endpoint;
    if (options.size() > 0) {
        baseUrl += "?";
        for (auto key : options.getAllKeys()) {
            baseUrl += key + "=" + options[key] + "&";
        }
    }
    URL url (baseUrl);
    url = url.withPOSTData(body);
    
    const String header = "Accept: application/json\n"
                          "Content-Type: application/json\n"
                          "Authorization: Bearer " + authToken + "\n";
    
    const ScopedPointer<InputStream> in (static_cast<InputStream*> (url.createInputStream (post, nullptr, nullptr, header, 0, nullptr, nullptr, 5, request)));
    if (in == nullptr) {
        return "";
    }
    jassert (in != nullptr);
    
//    DBG("SpotifyCurlInternal Reading: " << url.toString(true));

    const String response = in->readEntireStreamAsString();
//    DBG("SpotifyCurlInternal response: \n" << response);
    
    return response;
}

String SpotifyGET(String endpoint, StringPairArray options, String authToken, String body = "")
{
    return SpotifyCurlInternal("GET", endpoint, options, authToken, body);
}

String SpotifyPUT(String endpoint, StringPairArray options, String authToken, String body = "")
{
    return SpotifyCurlInternal("PUT", endpoint, options, authToken, body, true);
}

String SpotifyDELETE(String endpoint, StringPairArray options, String authToken, String body = "")
{
    return SpotifyCurlInternal("DELETE", endpoint, options, authToken, body, true);
}

String SpotifyPOST(String endpoint, StringPairArray options, String authToken, String body = "")
{
    return SpotifyCurlInternal("POST", endpoint, options, authToken, body, true);
}
    
PropertiesFile::Options WebAPI::createDefaultOptions()
{
    PropertiesFile::Options o;
    o.applicationName = "JUCESpotifyClient";
    o.osxLibrarySubFolder = "Application Support";
    o.folderName = "JUCESpotifyClient";
    o.filenameSuffix = ".spotify";
#if JUCE_DEBUG
    o.storageFormat = PropertiesFile::StorageFormat::storeAsXML;
#else
    o.storageFormat = PropertiesFile::StorageFormat::storeAsCompressedBinary;
#endif
    return o;
}
    
WebAPI::WebAPI()
: isCurrentlyConnected(false)
{
//    URL requestAuthenticationUrl (
//        "https://accounts.spotify.com/authorize?"
//        "client_id=" + String(SPOTIFY_CLIENT_ID) + "&"
//        "response_type=code&"
//        "redirect_uri=http://localhost:8888/callback&state=0&"
//        "scope=user-read-private "
//               "user-read-email "
//               "playlist-read-private "
//               "playlist-read-collaborative "
//               "playlist-modify-public "
//               "playlist-modify-private "
//               "user-follow-modify "
//               "user-follow-read "
//               "user-library-read "
//               "user-library-modify "
//               "user-read-private "
//               "user-read-birthdate "
//               "user-read-email "
//               "user-top-read "
//               "ugc-image-upload "
//               "user-read-playback-state "
//               "user-modify-playback-state "
//               "user-read-currently-playing "
//               "user-read-recently-played&"
//        "show_dialog=false"
//    );
//    jassert (requestAuthenticationUrl.isWellFormed());
//    DBG("Sending Request: " << requestAuthenticationUrl.toString(true));
//    const String response = requestAuthenticationUrl.readEntireTextStream(false);
    
//    File f("~/Desktop/h.html");
//    if (f.exists()) {
//        f.deleteFile();
//    }
//    f.create();
//    f.appendText(response);
    
//    spotifyAuthWindow = new SpotifyAuthWindow;
//    spotifyAuthWindow->getBrowser().goToURL(f.getFullPathName());
    
//    DBG("Response: \n" << response);
    properties.setStorageParameters(createDefaultOptions());
}
    
WebAPI::~WebAPI()
{
    clearSingletonInstance();
}

void WebAPI::connect()
{
    AuthenticationServer::start();
}
    
void WebAPI::addConnectionListener(ChangeListener* listener)
{
    getInstance()->addChangeListener(listener);
}
    
bool WebAPI::isConnected()
{
    return getInstance()->isCurrentlyConnected;
}
    
void WebAPI::setAuthToken(String authToken)
{
    getInstance()->isCurrentlyConnected = true;
    getInstance()->authToken = authToken;
    getInstance()->sendChangeMessage();
}
    
void WebAPI::setAuthStorageParameters(const juce::PropertiesFile::Options &options)
{
    getInstance()->properties.setStorageParameters(options);
}

Album WebAPI::getAlbum(String albumId, StringPairArray options)
{
    return Album(JSON::fromString(SpotifyGET("/v1/albums/" + albumId, options, getInstance()->authToken)));
}
    
Pager<Track> WebAPI::searchTracks(String query, StringPairArray options)
{
    options.set("type", "track,artist");
    options.set("q", query);
    return Pager<Track>(JSON::fromString(SpotifyGET("/v1/search", options, getInstance()->authToken))["tracks"]);
}

String WebAPI::searchTracksRaw(String query, StringPairArray options)
{
    options.set("type", "track,artist");
    options.set("q", query);
    return SpotifyGET("/v1/search", options, getInstance()->authToken);
}
    
void WebAPI::play(const String& uri, StringPairArray options)
{
    SpotifyPUT("/v1/me/player/play", options, getInstance()->authToken,
               (uri.isEmpty() ? "" : "{\"uris\":[\"" + uri + "\"]}"));
}

void WebAPI::pause(const String& uri, StringPairArray options)
{
    SpotifyPUT("/v1/me/player/pause", options, getInstance()->authToken,
               (uri.isEmpty() ? "" : "{\"uris\":[\"" + uri + "\"]}"));
}
    
CurrentlyPlayingTrack WebAPI::getMyCurrentPlayingTrack(StringPairArray options)
{
    String res = SpotifyGET("/v1/me/player/currently-playing", options, getInstance()->authToken);
    return res.isEmpty()
        ? CurrentlyPlayingTrack()
        : CurrentlyPlayingTrack(JSON::fromString(res));
}
    
AudioFeatures WebAPI::getAudioFeatures(String trackId, StringPairArray options)
{
    return AudioFeatures(JSON::fromString(SpotifyGET("/v1/audio-features/" + trackId, options, getInstance()->authToken)));
}

//Array<Album> WebAPI::GetAlbums(StringArray albumIds, StringPairArray options)
//{
//    Array<Album> albums;
//    for(auto albumId : albumIds) {
//        albums.add (GetAlbum (albumId, options));
//    }
//    return albums;
//}
//
//Pager<TrackSimple> WebAPI::GetAlbumTracks(String albumId, StringPairArray options)
//{
//    return Pager<TrackSimple>(SpotifyGET("/v1/albums/" + albumId + "/tracks", options, authToken));
//}
//
//Artist WebAPI::GetArtist(String artistId, StringPairArray options)
//{
//    return Artist(SpotifyGET("/v1/artists/" + artistId, options, authToken));
//}
//
//Array<Artist> WebAPI::GetArtists(StringArray artistIds, StringPairArray options)
//{
//    Array<Artist> artists;
//    for(auto artistId : artistIds) {
//        artists.add (GetArtist (artistId, options));
//    }
//    return artists;
//}
//
//Pager<AlbumSimple> WebAPI::GetArtistAlbums(String artistId, StringPairArray options)
//{
//    return Pager<AlbumSimple>(SpotifyGET("/v1/artists/" + artistId + "/albums", options, authToken));
//}
//
//Array<Track> WebAPI::GetArtistTopTracks(String artistId, String country, StringPairArray options)
//{
//    Array<Track> tracks;
//    options.set("country", country);
//    var json = SpotifyGET("/v1/artists/" + artistId + "/top-tracks", options, authToken);
//    for(auto trackJson : * json["tracks"].getArray()) {
//        tracks.add (Track (trackJson));
//    }
//    return tracks;
//}
//
//Array<Artist> WebAPI::GetArtistRelatedArtists(String artistId, StringPairArray options)
//{
//    Array<Artist> artists;
//    var json = SpotifyGET("/v1/artists/" + artistId + "/related-artists", options, authToken);
//    for(auto artistJson : * json["artists"].getArray()) {
//        artists.add (Artist (artistJson));
//    }
//    return artists;
//}
//
//
//Array<AudioFeatures> WebAPI::GetAudioFeatures(StringArray trackIds, StringPairArray options)
//{
//    Array<AudioFeatures> audioFeatures;
//    for(auto trackId : trackIds) {
//        audioFeatures.add (GetAudioFeatures (trackId, options));
//    }
//    return audioFeatures;
//}
//
//Pager<PlaylistSimple> WebAPI::GetFeaturedPlaylists(StringPairArray options)
//{
//    // TODO Add access to message variable
//    return Pager<PlaylistSimple>(SpotifyGET("/v1/browse/featured-playlists", options, authToken)["playlists"]);
//}
//
//Pager<AlbumSimple> WebAPI::GetNewReleases(StringPairArray options)
//{
//    return Pager<AlbumSimple>(SpotifyGET("/v1/browse/new-releases", options, authToken)["albums"]);
//}
//
//Pager<Category> WebAPI::GetCategories(StringPairArray options)
//{
//    return Pager<Category>(SpotifyGET("/v1/browse/categories", options, authToken)["categories"]);
//}
//
//Category WebAPI::GetCategory(String categoryId, StringPairArray options)
//{
//    return Category(SpotifyGET("/v1/browse/categories/" + categoryId, options, authToken));
//}
//
//Pager<PlaylistSimple> WebAPI::GetCategoryPlaylists(String categoryId, StringPairArray options)
//{
//    return Pager<PlaylistSimple>(SpotifyGET("/v1/browse/categories/" + categoryId + "/playlists", options, authToken)["playlists"]);
//}
//
//User WebAPI::GetMe(StringPairArray options)
//{
//    return User(SpotifyGET("/v1/me", options, authToken));
//}
//
//CursorPager<Artist> WebAPI::GetMyFollowedArtists(StringPairArray options)
//{
//    options.set("type", "artist");
//    return CursorPager<Artist>(SpotifyGET("/v1/me/following", options, authToken)["artists"]);
//}
//
//void WebAPI::FollowArtist(String artistId, StringPairArray options)
//{
//    options.set("type", "artist");
//    options.set("ids", artistId);
//    SpotifyPUT("/v1/me/following", options, authToken);
//}
//
//void WebAPI::FollowUser(String userId, StringPairArray options)
//{
//    options.set("type", "user");
//    options.set("ids", userId);
//    SpotifyPUT("/v1/me/following", options, authToken);
//}
//
//void WebAPI::UnfollowArtist(String artistId, StringPairArray options)
//{
//    options.set("type", "artist");
//    options.set("ids", artistId);
//    SpotifyDELETE("/v1/me/following", options, authToken);
//}
//
//void WebAPI::UnfollowUser(String userId, StringPairArray options)
//{
//    options.set("type", "user");
//    options.set("ids", userId);
//    SpotifyDELETE("/v1/me/following", options, authToken);
//}
//
//bool WebAPI::CheckFollowingArtist(String artistId, StringPairArray options)
//{
//    options.set("type", "artist");
//    options.set("ids", artistId);
//    return SpotifyGET("/v1/me/following/contains", options, authToken)[0];
//}
//
//bool WebAPI::CheckFollowingUser(String userId, StringPairArray options)
//{
//    options.set("type", "user");
//    options.set("ids", userId);
//    return SpotifyGET("/v1/me/following/contains", options, authToken)[0];
//}
//
//void WebAPI::FollowPlaylist(String ownerId, String playlistId, StringPairArray options)
//{
//    SpotifyPUT("/v1/users/" + ownerId + "/playlists/" + playlistId + "/followers", options, authToken);
//}
//
//void WebAPI::UnfollowPlaylist(String ownerId, String playlistId, StringPairArray options)
//{
//    SpotifyDELETE("/v1/users/" + ownerId + "/playlists/" + playlistId + "/followers", options, authToken);
//}
//
//void WebAPI::SaveTracks(StringArray trackIds, StringPairArray options)
//{
//    options.set("ids", trackIds.joinIntoString(","));
//    SpotifyPUT("/v1/me/tracks", options, authToken);
//}
//
//Pager<SavedTrack> WebAPI::GetMySavedTracks(StringPairArray options)
//{
//    return Pager<SavedTrack>(SpotifyGET("/v1/me/tracks", options, authToken));
//}
//
//void WebAPI::RemoveSavedTracks(StringArray trackIds, StringPairArray options)
//{
//    options.set("ids", trackIds.joinIntoString(","));
//    SpotifyDELETE("/v1/me/tracks", options, authToken);
//}
//
//bool WebAPI::CheckSavedTracks(StringArray trackIds, StringPairArray options)
//{
//    options.set("ids", trackIds.joinIntoString(","));
//    return SpotifyGET("/v1/me/tracks/contains", options, authToken)[0];
//}
//
//void WebAPI::SaveAlbums(StringArray albumIds, StringPairArray options)
//{
//    options.set("ids", albumIds.joinIntoString(","));
//    SpotifyPUT("/v1/me/albums", options, authToken);
//}
//
//Pager<SavedAlbum> WebAPI::GetMySavedAlbums(StringPairArray options)
//{
//    return Pager<SavedAlbum>(SpotifyGET("/v1/me/albums", options, authToken));
//}
//
//void WebAPI::RemoveSavedAlbums(StringArray albumIds, StringPairArray options)
//{
//    options.set("ids", albumIds.joinIntoString(","));
//    SpotifyDELETE("/v1/me/albums", options, authToken);
//}
//
//bool WebAPI::CheckSavedAlbums(StringArray albumIds, StringPairArray options)
//{
//    options.set("ids", albumIds.joinIntoString(","));
//    return SpotifyGET("/v1/me/albums/contains", options, authToken)[0];
//}
//
//Pager<Artist> WebAPI::GetMyTopArtists(StringPairArray options)
//{
//    return Pager<Artist>(SpotifyGET("/v1/me/top/artists", options, authToken));
//}
//
//Pager<Track> WebAPI::GetMyTopTracks(StringPairArray options)
//{
//    return Pager<Track>(SpotifyGET("/v1/me/top/tracks", options, authToken));
//}
//
//Recommendations WebAPI::GetRecommendations(StringPairArray options)
//{
//    return Recommendations(SpotifyGET("/v1/recommendations", options, authToken));
//}
//
//Pager<AlbumSimple> WebAPI::SearchAlbums(String query, StringPairArray options)
//{
//    options.set("type", "album");
//    options.set("q", query);
//    return Pager<AlbumSimple>(SpotifyGET("/v1/search", options, authToken)["albums"]);
//}
//
//Pager<Artist> WebAPI::SearchArtists(String query, StringPairArray options)
//{
//    options.set("type", "artist");
//    options.set("q", query);
//    return Pager<Artist>(SpotifyGET("/v1/search", options, authToken)["artists"]);
//}
//
//Pager<PlaylistSimple> WebAPI::SearchPlaylists(String query, StringPairArray options)
//{
//    options.set("type", "playlist");
//    options.set("q", query);
//    return Pager<PlaylistSimple>(SpotifyGET("/v1/search", options, authToken)["playlists"]);
//}
//

//
//Track WebAPI::GetTrack(String trackId, StringPairArray options)
//{
//    return Track(SpotifyGET("/v1/tracks/" + trackId, options, authToken));
//}
//
//Array<Track> WebAPI::GetTracks(StringArray trackIds, StringPairArray options)
//{
//    Array<Track> tracks;
//    for(String trackId : trackIds) {
//        tracks.add (GetTrack (trackId, options));
//    }
//    return tracks;
//}
//
//UserPublic WebAPI::GetUser(String userId, StringPairArray options)
//{
//    return UserPublic(SpotifyGET("/v1/users/" + userId, options, authToken));
//}
//
//Pager<PlaylistSimple> WebAPI::GetUserPlaylists(String userId, StringPairArray options)
//{
//    return Pager<PlaylistSimple>(SpotifyGET("/v1/users/" + userId + "/playlists", options, authToken));
//}
//
//Pager<PlaylistSimple> WebAPI::GetMyPlaylists(StringPairArray options)
//{
//    return Pager<PlaylistSimple>(SpotifyGET("/v1/me/playlists", options, authToken));
//}
//
//Playlist WebAPI::GetPlaylist(String userId, String playlistId, StringPairArray options)
//{
//    return Playlist(SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId, options, authToken));
//}
//
//Pager<PlaylistTrack> WebAPI::GetPlaylistTracks(String userId, String playlistId, StringPairArray options)
//{
//    return Pager<PlaylistTrack>(SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken));
//}
//
////Playlist WebAPI::CreatePlaylist(String userId, String name, StringPairArray options)
////{
////    var bodyJson;
////    bodyJson["name"] = name;
////    for(auto option : options) {
////        bodyJson[option.first] = option.second;
////    }
////
////    return Playlist(SpotifyPOST("/v1/users/" + userId + "/playlists", StringPairArray(), authToken, bodyJson.dump(4)));
////}
////
////void WebAPI::EditPlaylist(String userId, String playlistId, StringPairArray options)
////{
////    var bodyJson;
////    for(auto option : options)
////        bodyJson[option.first] = option.second;
////
////    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId, StringPairArray(), authToken, bodyJson.dump(4));
////}
////
////void WebAPI::AddTracksToPlaylist(String userId, String playlistId, StringArray trackUris,
////                                     StringPairArray options)
////{
////    options["uris"] = VectorJoin(trackUris);
////    SpotifyPOST("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken);
////}
//
////void WebAPI::RemoveTracksFromPlaylist(String userId, String playlistId, StringArray trackIds, String snapshotId)
////{
////    var bodyJson;
////    for(String trackId : trackIds)
////    {
////        var uriJson;
////        uriJson["uri"] = trackId;
////        bodyJson["tracks"].push_back(uriJson);
////    }
////    if(!snapshotId.empty())
////        bodyJson["snapshot_id"] = snapshotId;
////
////    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", StringPairArray(), authToken, bodyJson.dump(4));
////}
////
////void WebAPI::RemoveTracksFromPlaylist(String userId, String playlistId,
////                                          std::map<String, std::vector<int>> trackUrisToPositions,
////                                          String snapshotId)
////{
////    var bodyJson;
////    for(auto trackIdToPositions : trackUrisToPositions)
////    {
////        var uriJson;
////        uriJson["uri"] = trackIdToPositions.first;
////        for(int position : trackIdToPositions.second)
////            uriJson["positions"].push_back(position);
////        bodyJson["tracks"].push_back(uriJson);
////    }
////    if(!snapshotId.empty())
////        bodyJson["snapshot_id"] = snapshotId;
////
////    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", StringPairArray(), authToken, bodyJson.dump(4));
////}
//
////void WebAPI::RemoveTracksFromPlaylist(String userId, String playlistId, std::vector<int> positions,
////                                          String snapshotId)
////{
////    var bodyJson;
////    for(int position : positions)
////        bodyJson["positions"].push_back(position);
////    bodyJson["snapshot_id"] = snapshotId;
////
////    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", StringPairArray(), authToken, bodyJson.dump(4));
////}
////
////void WebAPI::ReorderPlaylistTracks(String userId, String playlistId, int rangeStart, int insertBefore,
////                                       StringPairArray options)
////{
////    var bodyJson;
////    bodyJson["range_start"] = rangeStart;
////    bodyJson["insert_before"] = insertBefore;
////    for(auto option : options)
////        bodyJson[option.first] = option.second;
////
////    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", StringPairArray(), authToken, bodyJson.dump(4));
////}
////
////void WebAPI::ReplacePlaylistTracks(String userId, String playlistId, StringArray trackUris,
////                                       StringPairArray options)
////{
////    options["uris"] = VectorJoin(trackUris);
////    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken);
////}
////
////bool WebAPI::CheckUserFollowingPlaylist(String userId, String playlistId, StringArray userIds,
////                                            StringPairArray options)
////{
////    //TODO Support multiple users
////    options["ids"] = VectorJoin(userIds);
////    return SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId + "/followers/contains", options, authToken)[0];
////}
//
//void WebAPI::UploadCustomPlaylistCover(String userId,
//                                       String playlistId,
//                                       String contentType,
//                                       String image,
//                                       StringPairArray options)
//{
//
//}
//
//CursorPager<PlayHistoryObject> WebAPI::GetMyRecentlyPlayed(StringPairArray options)
//{
//
//}
//
//Array<Device> WebAPI::GetMyDevices(StringPairArray options)
//{
//
//}
//
//CurrentlyPlayingContext WebAPI::GetMyCurrentPlayback(StringPairArray options)
//{
//
//}
//
//
//void WebAPI::TransferMyPlayback(String deviceId, StringPairArray options)
//{
//
//}
//
//void WebAPI::Resume(StringPairArray options)
//{
//
//}
//

//
//void WebAPI::SkipToNext(StringPairArray options)
//{
//
//}
//
//void WebAPI::SkipToPrevious(StringPairArray options)
//{
//
//}
//
//void WebAPI::SetRepeat(String state, StringPairArray options)
//{
//
//}
//
//void WebAPI::SetVolume(int volumePercent, StringPairArray options)
//{
//
//}
//
//void WebAPI::ToggleShuffle(bool state, StringPairArray options)
//{
//
//}

}
