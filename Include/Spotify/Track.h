/*
 * Copyright 2011 Jim Knowler
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#pragma once

// std include
#include <string>

// libspotify include
#include "libspotify/api.h"

// Local Includes
#include "Spotify/PlayListElement.h"
#include "Spotify/Artist.h"
#include "Spotify/Album.h"

// boost includes
#include <boost/shared_ptr.hpp>

namespace Spotify
{
	// forward declaration
	class Session;

	class Track : public PlayListElement
	{
	public:
		Track( boost::shared_ptr<Session> session );
		virtual ~Track();

		virtual bool Load( sp_track* track );

		virtual void Unload();

		virtual bool IsLoading( bool recursive );

		virtual std::string GetName();

		virtual int GetDuration();

		virtual bool HasChildren();
		
		virtual int GetNumChildren();

		virtual boost::shared_ptr<PlayListElement> GetChild( int index );

		virtual eType GetType();
	
		virtual int GetNumArtists();

		virtual boost::shared_ptr<Artist> GetArtist( int index );

		virtual boost::shared_ptr<Album> GetAlbum();

		virtual int GetDisc();

		virtual int GetPopularity();

		virtual bool IsStarred();

		virtual void SetStarred( bool isStarred );
		
		virtual void DumpToTTY( int level = 0 );

	private:
		friend class Session;

		sp_track*	m_pTrack;
	};
}