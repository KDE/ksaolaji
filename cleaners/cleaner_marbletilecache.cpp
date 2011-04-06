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

#include "cleaner_marbletilecache.h"

#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerMarbleTileCache::CleanerMarbleTileCache()
{
}

CleanerMarbleTileCache::~CleanerMarbleTileCache()
{
}

QString CleanerMarbleTileCache::uniqueName()
{
    return QString( "marble_tile_cache" );
}

QString CleanerMarbleTileCache::description()
{
    return i18n( "Marble tile cache" );
}

QString CleanerMarbleTileCache::iconName()
{
    return QString( "marble" );
}

bool CleanerMarbleTileCache::youlaji()
{
    QDBusConnectionInterface* i = QDBusConnection::sessionBus().interface();
    QDBusReply<QStringList> servicesReply = i->registeredServiceNames();
    QStringList services = servicesReply.value();
    QStringList::ConstIterator it = services.constBegin();
    QStringList::ConstIterator end = services.constEnd();
    while ( it != end ) {
        const QString service = *it;
        ++it;
        if ( service.startsWith( "org.kde.marble-" ) ) {
            /// always true for running marble
            return true;
        }
    }

    return false;
}

bool CleanerMarbleTileCache::saolaji()
{
    bool marbleRunning = false;
    QDBusConnectionInterface* i = QDBusConnection::sessionBus().interface();
    QDBusReply<QStringList> servicesReply = i->registeredServiceNames();
    QStringList services = servicesReply.value();
    QStringList::ConstIterator it = services.constBegin();
    QStringList::ConstIterator end = services.constEnd();
    while ( it != end ) {
        const QString service = *it;
        ++it;
        if ( service.startsWith( "org.kde.marble-" ) ) {
            marbleRunning = true;
            kWarning() << service;
            QDBusInterface marble( service, "/MarbleWidget", "org.kde.MarbleWidget" );
            kWarning() << marble.call( "clearPersistentTileCache" );
        }
    }

    if ( marbleRunning )
        return true;

    return true;
}
