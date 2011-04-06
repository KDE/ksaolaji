/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>

 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cleaner_gwenview.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KStandardDirs>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerGwenview::CleanerGwenview()
{
}

CleanerGwenview::~CleanerGwenview()
{
}

QString CleanerGwenview::uniqueName()
{
    return QString( "gwenview_recent_files_and_urls" );
}

QString CleanerGwenview::description()
{
    return i18n( "Gwenview recent files and URLs" );
}

QString CleanerGwenview::iconName()
{
    return QString( "gwenview" );
}

bool CleanerGwenview::youlaji()
{
    QDir rfdir( KStandardDirs::locateLocal( "data", "gwenview/recentfolders" ) );
    QStringList rfs = rfdir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QDir rudir( KStandardDirs::locateLocal( "data", "gwenview/recenturls" ) );
    QStringList rus = rudir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    KConfig c( "gwenviewrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return !rfs.isEmpty() || !rus.isEmpty() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerGwenview::saolaji()
{
    KIO::Job* rfjob = KIO::del( KStandardDirs::locateLocal( "data", "gwenview/recentfolders" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( rfjob, 0 );

    KIO::Job* rujob = KIO::del( KStandardDirs::locateLocal( "data", "gwenview/recenturls" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( rujob, 0 );

    KConfig c( "gwenviewrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
