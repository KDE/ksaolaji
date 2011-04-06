/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cleaner_plasmawallpaper.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerPlasmaWallpaper::CleanerPlasmaWallpaper()
{
}

CleanerPlasmaWallpaper::~CleanerPlasmaWallpaper()
{
}

QString CleanerPlasmaWallpaper::uniqueName()
{
    return QString( "plasma_wallpaper_image_cache" );
}

QString CleanerPlasmaWallpaper::description()
{
    return i18n( "Plasma wallpaper image cache" );
}

QString CleanerPlasmaWallpaper::iconName()
{
    return QString( "plasma-desktop" );
}

bool CleanerPlasmaWallpaper::youlaji()
{
    QDir snapdir( KStandardDirs::locateLocal( "cache", "plasma-wallpapers" ) );
    QStringList snapfs = snapdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !snapfs.isEmpty();
}

bool CleanerPlasmaWallpaper::saolaji()
{
    KIO::Job* sfjob = KIO::del( KStandardDirs::locateLocal( "cache", "plasma-wallpapers" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( sfjob, 0 );
    return true;
}
