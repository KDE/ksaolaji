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

#include "cleaner_kdeglobal.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKDEGlobal::CleanerKDEGlobal()
{
}

CleanerKDEGlobal::~CleanerKDEGlobal()
{
}

QString CleanerKDEGlobal::uniqueName()
{
    return QString( "kde_global_history_items_and_recent_urls" );
}

QString CleanerKDEGlobal::description()
{
    return i18n( "KDE global history items and recent URLs" );
}

QString CleanerKDEGlobal::iconName()
{
    return QString( "start-here-kde" );
}

bool CleanerKDEGlobal::youlaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( group.exists() && group.hasKey( "History Items" ) )
            || ( fs.exists() && fs.hasKey( "Recent URLs" ) );
}

bool CleanerKDEGlobal::saolaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    group.deleteEntry( "History Items" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent URLs" );
    c.sync();
    return true;
}
