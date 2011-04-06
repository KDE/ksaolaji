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

#include "cleaner_konqlocbar.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKonqLocBar::CleanerKonqLocBar()
{
}

CleanerKonqLocBar::~CleanerKonqLocBar()
{
}

QString CleanerKonqLocBar::uniqueName()
{
    return QString( "konqueror_location_bar_contents_and_icon_cache" );
}

QString CleanerKonqLocBar::description()
{
    return i18n( "Konqueror location bar contents and icon cache" );
}

QString CleanerKonqLocBar::iconName()
{
    return QString( "konqueror" );
}

bool CleanerKonqLocBar::youlaji()
{
    KConfig c( "konq_history" , KConfig::NoGlobals );
    KConfigGroup lb( &c, "Location Bar" );
    return lb.exists() && ( lb.hasKey( "ComboContents" ) || lb.hasKey( "ComboIconCache" ) );
}

bool CleanerKonqLocBar::saolaji()
{
    KConfig c( "konq_history" , KConfig::NoGlobals );
    KConfigGroup lb( &c, "Location Bar" );
    lb.deleteEntry( "ComboContents" );
    lb.deleteEntry( "ComboIconCache" );
    c.sync();
    return true;
}
