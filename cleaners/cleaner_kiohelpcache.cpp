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

#include "cleaner_kiohelpcache.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKIOHelpCache::CleanerKIOHelpCache()
{
}

CleanerKIOHelpCache::~CleanerKIOHelpCache()
{
}

QString CleanerKIOHelpCache::uniqueName()
{
    return QString( "kde_help_handbook_cache" );
}

QString CleanerKIOHelpCache::description()
{
    return i18n( "KDE help handbook cache" );
}

QString CleanerKIOHelpCache::iconName()
{
    return QString( "help-browser" );
}

bool CleanerKIOHelpCache::youlaji()
{
    QDir kiohelpdir( KStandardDirs::locateLocal( "cache", "kio_help" ) );
    QStringList kiohelpfs = kiohelpdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir helpdir( KStandardDirs::locateLocal( "cache", "help" ) );
    QStringList helpfs = helpdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !kiohelpfs.isEmpty() || !helpfs.isEmpty();
}

bool CleanerKIOHelpCache::saolaji()
{
    KIO::Job* kiohelpjob = KIO::del( KStandardDirs::locateLocal( "cache", "kio_help" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( kiohelpjob, 0 );
    KIO::Job* helpjob = KIO::del( KStandardDirs::locateLocal( "cache", "help" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( helpjob, 0 );
    return true;
}
