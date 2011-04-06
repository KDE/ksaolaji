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

#include "cleaner_kget.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKGet::CleanerKGet()
{
}

CleanerKGet::~CleanerKGet()
{
}

QString CleanerKGet::uniqueName()
{
    return QString( "kget_recent_files_and_last_directory" );
}

QString CleanerKGet::description()
{
    return i18n( "KGet recent files and last directory" );
}

QString CleanerKGet::iconName()
{
    return QString( "kget" );
}

bool CleanerKGet::youlaji()
{
    KConfig c( "kgetrc" , KConfig::NoGlobals );
    KConfigGroup in( &c, "Internal" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( in.exists() && in.hasKey( "LastDirectory" ) ) || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKGet::saolaji()
{
    KConfig c( "kgetrc" , KConfig::NoGlobals );
    KConfigGroup in( &c, "Internal" );
    in.deleteEntry( "LastDirectory" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
