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

#include "cleaner_kpixmapcache.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKPixmapCache::CleanerKPixmapCache()
{
}

CleanerKPixmapCache::~CleanerKPixmapCache()
{
}

QString CleanerKPixmapCache::uniqueName()
{
    return QString( "kde_pixmap_cache" );
}

QString CleanerKPixmapCache::description()
{
    return i18n( "KDE pixmap cache" );
}

QString CleanerKPixmapCache::iconName()
{
    return QString( "preferences-desktop-icons" );
}

bool CleanerKPixmapCache::youlaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "kpc" ) );
    QStringList kpcfs = cachedir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !kpcfs.isEmpty();
}

bool CleanerKPixmapCache::saolaji()
{
    KIO::Job* kpcjob = KIO::del( KStandardDirs::locateLocal( "cache", "kpc" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( kpcjob, 0 );
    return true;
}
