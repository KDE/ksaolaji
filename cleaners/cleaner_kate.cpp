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

#include "cleaner_kate.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKate::CleanerKate()
{
}

CleanerKate::~CleanerKate()
{
}

QString CleanerKate::uniqueName()
{
    return QString( "kate_search_replace_patterns_and_recent_files" );
}

QString CleanerKate::description()
{
    return i18n( "Kate search replace patterns and recent files" );
}

QString CleanerKate::iconName()
{
    return QString( "kate" );
}

bool CleanerKate::youlaji()
{
    KConfig c( "katerc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    KConfigGroup kvd( &c, "Kate View Defaults" );
    return ( fs.exists() && fs.hasKey( "Recent Files" ) )
            || ( kvd.exists() && ( kvd.hasKey( "Replacement Text History" ) || kvd.hasKey( "Search Pattern History" ) ) );
}

bool CleanerKate::saolaji()
{
    KConfig c( "katerc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    KConfigGroup kvd( &c, "Kate View Defaults" );
    kvd.deleteEntry( "Replacement Text History" );
    kvd.deleteEntry( "Search Pattern History" );
    c.sync();
    return true;
}
