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

#include "cleaner_konqueror.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKonqueror::CleanerKonqueror()
{
}

CleanerKonqueror::~CleanerKonqueror()
{
}

QString CleanerKonqueror::uniqueName()
{
    return QString( "konqueror_open_with_history_and_recent_files" );
}

QString CleanerKonqueror::description()
{
    return i18n( "Konqueror \"Open with\" history and recent files" );
}

QString CleanerKonqueror::iconName()
{
    return QString( "konqueror" );
}

bool CleanerKonqueror::youlaji()
{
    KConfig c( "konquerorrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( group.exists() && group.hasKey( "History" ) )
            || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKonqueror::saolaji()
{
    KConfig c( "konquerorrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    group.deleteEntry( "History" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
