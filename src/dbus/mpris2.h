// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2011 J.Rios
//	anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#ifndef MPRIS2_H
#define MPRIS2_H

#include "gudbus.h"
#include "PlayerPanel.h"

// -------------------------------------------------------------------------------- //
class guMPRIS2 : public guDBusClient
{
  protected :
    static guMPRIS2 *           m_MPRIS2;
    guPlayerPanel *             m_PlayerPanel;

  public :
    guMPRIS2( guDBusServer * server, guPlayerPanel * playerpanel );
    ~guMPRIS2();

    virtual DBusHandlerResult   HandleMessages( guDBusMessage * msg, guDBusMessage * reply = NULL );

    void                        OnPlayerTrackChange( void );
    void                        OnPlayerStatusChange( void );
    void                        OnPlayerCapsChange( void );
    void                        OnPlayerVolumeChange( void );
    void                        OnTrackListChange( void );

    bool                        Indicators_Sound_Available( void );
    int                         Indicators_Sound_BlacklistMediaPlayer( const dbus_bool_t blacklist = true );
    int                         Indicators_Sound_IsBlackListed( void );

    static void                 Set( guMPRIS2 * object ) { m_MPRIS2 = object; }
    static guMPRIS2 *           Get( void ) { return m_MPRIS2; }

};


#endif

// -------------------------------------------------------------------------------- //
