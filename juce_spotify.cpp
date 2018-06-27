#ifdef JUCE_SPOTIFY_H_INCLUDED
/* When you add this cpp file to your project, you mustn't include it in a file where you've
 already included any other headers - just put it inside a file on its own, possibly with your config
 flags preceding it, but don't include anything else. That also includes avoiding any automatic prefix
 header files that the compiler may be using.
 */
#error "Incorrect use of JUCE cpp file"
#endif

#if _WIN32
#pragma warning(push)
#pragma warning(disable : 4100)
#endif

#include "juce_spotify.h"
using namespace juce;

#include "models/spotify_AlbumSimple.cpp"
#include "models/spotify_Album.cpp"
#include "models/spotify_Artist.cpp"
#include "models/spotify_ArtistSimple.cpp"
#include "models/spotify_AudioFeatures.cpp"
#include "models/spotify_Category.cpp"
#include "models/spotify_Context.cpp"
#include "models/spotify_Copyright.cpp"
#include "models/spotify_CurrentlyPlayingContext.cpp"
#include "models/spotify_CurrentlyPlayingTrack.cpp"
#include "models/spotify_Cursor.cpp"
#include "models/spotify_Device.cpp"
#include "models/spotify_Error.cpp"
#include "models/spotify_Followers.cpp"
#include "models/spotify_Image.cpp"
#include "models/spotify_PlayHistoryObject.cpp"
#include "models/spotify_Playlist.cpp"
#include "models/spotify_PlaylistSimple.cpp"
#include "models/spotify_PlaylistTrack.cpp"
#include "models/spotify_Recommendations.cpp"
#include "models/spotify_RecommendationsSeed.cpp"
#include "models/spotify_SavedAlbum.cpp"
#include "models/spotify_SavedTrack.cpp"
#include "models/spotify_Track.cpp"
#include "models/spotify_TrackLink.cpp"
#include "models/spotify_TrackSimple.cpp"
#include "models/spotify_User.cpp"
#include "models/spotify_UserPublic.cpp"

#include "web_api/spotify_Authentication.cpp"
#include "web_api/spotify_WebAPI.cpp"

#if _WIN32
#pragma warning(pop)
#endif
