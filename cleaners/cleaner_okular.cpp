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

#include "cleaner_okular.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerOkular::CleanerOkular()
{
}

CleanerOkular::~CleanerOkular()
{
}

QString CleanerOkular::uniqueName()
{
    return QString( "okular_recent_files" );
}

QString CleanerOkular::description()
{
    return i18n( "Okular recent files" );
}

QString CleanerOkular::iconName()
{
    return QString( "okular" );
}

bool CleanerOkular::youlaji()
{
    KConfig c( "okularrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerOkular::saolaji()
{
    KConfig c( "okularrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
