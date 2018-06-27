/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details about the syntax and how to create or use a module, see the
 JUCE Module Format.txt file.
 
 
 BEGIN_JUCE_MODULE_DECLARATION
 
 ID:               juce_spotify
 vendor:           open
 version:          5.3.1
 name:             JUCE Spotify Web API
 description:      Wrapper for the Spotify Web API
 website:          https://beta.developer.spotify.com/documentation/web-api/quick-start/
 license:          MIT
 
 dependencies:     juce_core juce_data_structures juce_events juce_gui_extra juce_mongoose
 
 END_JUCE_MODULE_DECLARATION
 
 *******************************************************************************/


#pragma once
#define JUCE_SPOTIFY_H_INCLUDED

#if _WIN32
#pragma warning(push)
#pragma warning (disable : 4100)
#endif

#include <juce_core/juce_core.h>
#include <juce_data_structures/juce_data_structures.h>
#include <juce_events/juce_events.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include <juce_mongoose/juce_mongoose.h>

#include "models/spotify_Pager.h"
#include "models/spotify_Copyright.h"
#include "models/spotify_Image.h"
#include "models/spotify_Followers.h"
#include "models/spotify_ArtistSimple.h"
#include "models/spotify_AlbumSimple.h"
#include "models/spotify_Album.h"
#include "models/spotify_Artist.h"
#include "models/spotify_AudioFeatures.h"
#include "models/spotify_Category.h"
#include "models/spotify_Context.h"
#include "models/spotify_TrackLink.h"
#include "models/spotify_TrackSimple.h"
#include "models/spotify_Track.h"
#include "models/spotify_Device.h"
#include "models/spotify_CurrentlyPlayingContext.h"
#include "models/spotify_CurrentlyPlayingTrack.h"
#include "models/spotify_Cursor.h"
#include "models/spotify_CursorPager.h"
#include "models/spotify_Error.h"
#include "models/spotify_PlayHistoryObject.h"
#include "models/spotify_UserPublic.h"
#include "models/spotify_User.h"
#include "models/spotify_PlaylistTrack.h"
#include "models/spotify_PlaylistSimple.h"
#include "models/spotify_Playlist.h"
#include "models/spotify_RecommendationsSeed.h"
#include "models/spotify_Recommendations.h"
#include "models/spotify_SavedAlbum.h"
#include "models/spotify_SavedTrack.h"

#include "web_api/spotify_Authentication.h"
#include "web_api/spotify_WebAPI.h"
