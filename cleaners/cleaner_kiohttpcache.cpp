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

#include "cleaner_kiohttpcache.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QProcess>

CleanerKIOHttpCache::CleanerKIOHttpCache()
{
}

CleanerKIOHttpCache::~CleanerKIOHttpCache()
{
}

bool CleanerKIOHttpCache::isThreadSafe() const
{
    return true;
}

QString CleanerKIOHttpCache::uniqueName()
{
    return QString( "kde_http_cache" );
}

QString CleanerKIOHttpCache::description()
{
    return i18n( "KDE HTTP cache" );
}

QString CleanerKIOHttpCache::iconName()
{
    return QString( "preferences-web-browser-cache" );
}

bool CleanerKIOHttpCache::youlaji()
{
    /// TODO: any way to decide this ? --- nihui
    return true;
}

bool CleanerKIOHttpCache::saolaji()
{
    QString execfile = KStandardDirs::findExe( "kio_http_cache_cleaner" );
    QProcess::execute( execfile, QStringList() << "--clear-all" );
    return true;
}
