/*
 * SPDX-License-Identifier: LGPL-3.0-or-later
 *
 * Copyright (C) 2020-2026 Stage Lab Coop.
 * Authors:
 *   Alex Ramos <alex@stagelab.coop>
 *   Ion Reguera <ion@stagelab.coop>
 *
 * This file is part of cuemslogger.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Stage Lab Cuems logger class header file
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#ifndef CUEMSLOGGER_H
#define CUEMSLOGGER_H

#include <string>
#include <filesystem>
#include <syslog.h>

using namespace std;
namespace fs = std::filesystem;

class CuemsLogger
{
    public:
        CuemsLogger( const string slug = "CuemsLog" );
        ~CuemsLogger( void );

        void logEmergency( const string& message );
        void logAlert( const string& message );
        void logCritical( const string& message );
        void logError( const string& message );
        void logWarning( const string& message );
        void logNotice( const string& message );
        void logInfo( const string& message );
        void logDebug( const string& message );

        void logOK( const string& message );

        // Static funcion to get our singleton pointer everywhere
        static CuemsLogger* getLogger( void );

        void setNewSlug( const string newSlug );
        string getSlug( void );
        bool isLogOpen( void );

    private:
        // Log file path
        static std::string programSlug;

        // Our own singleton pointer
        static CuemsLogger* myObjectPointer;

        CuemsLogger(const CuemsLogger&) {};
        CuemsLogger& operator=(const CuemsLogger&){ return *this; };
        
        void log( const string& message );

};

#endif // CUEMSLOGGER_H