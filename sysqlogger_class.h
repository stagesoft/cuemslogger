/* LICENSE TEXT

    audioplayer for linux based using RtAudio and RtMidi libraries to
    process audio and receive MTC sync. It also uses oscpack to receive
    some configurations through osc commands.
    Copyright (C) 2020  Stage Lab & bTactic.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Stage Lab SysQ logger class header file
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#ifndef SYSQLOGGER_CLASS_H
#define SYSQLOGGER_CLASS_H

#include <string>
#include <filesystem>
#include <syslog.h>

using namespace std;
namespace fs = std::filesystem;

class SysQLogger
{
    public:
        SysQLogger( const string slug = "SysQLog" );
        ~SysQLogger( void );

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
        static SysQLogger* getLogger( void );

        void setNewSlug( const string newSlug );
        string getSlug( void );
        bool isLogOpen( void );

    private:
        // Log file path
        static std::string programSlug;

        // Our own singleton pointer
        static SysQLogger* myObjectPointer;

        SysQLogger(const SysQLogger&) {};
        SysQLogger& operator=(const SysQLogger&){ return *this; };
        
        void log( const string& message );

};

#endif // SYSQLOGGER_CLASS_H