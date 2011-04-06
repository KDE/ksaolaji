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

#include "cleaner_kolourpaint.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKolourPaint::CleanerKolourPaint()
{
}

CleanerKolourPaint::~CleanerKolourPaint()
{
}

QString CleanerKolourPaint::uniqueName()
{
    return QString( "kolourpaint_recent_files_and_image_size_info" );
}

QString CleanerKolourPaint::description()
{
    return i18n( "Kolourpaint recent files and image size info" );
}

QString CleanerKolourPaint::iconName()
{
    return QString( "kolourpaint" );
}

bool CleanerKolourPaint::youlaji()
{
    KConfig c( "kolourpaintrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup gs( &c, "General Settings" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( gs.exists() && gs.hasKey( "Last Document Size" ) )
            || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKolourPaint::saolaji()
{
    KConfig c( "kolourpaintrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup gs( &c, "General Settings" );
    gs.deleteEntry( "Last Document Size" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
