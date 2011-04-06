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

#include "cleaner_klipper.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>
#include <QDBusReply>

CleanerKlipper::CleanerKlipper()
{
}

CleanerKlipper::~CleanerKlipper()
{
}

QString CleanerKlipper::uniqueName()
{
    return QString( "klipper_history" );
}

QString CleanerKlipper::description()
{
    return i18n( "Klipper history" );
}

QString CleanerKlipper::iconName()
{
    return QString( "klipper" );
}

bool CleanerKlipper::youlaji()
{
    if ( !QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.klipper" ) ) {
        KConfig c( "klipperrc" , KConfig::NoGlobals );
        KConfigGroup group( &c, "General" );
        return group.exists();
    }

    QDBusInterface klipper( "org.kde.klipper", "/klipper", "org.kde.klipper.klipper" );
    QDBusReply<QString> reply = klipper.call( "getClipboardContents" );
    return reply.isValid() && !reply.value().isEmpty();
}

bool CleanerKlipper::saolaji()
{
    if ( !QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.klipper" ) ) {
        KConfig c( "klipperrc" , KConfig::NoGlobals );
        KConfigGroup group( &c, "General" );
        group.deleteEntry( "ClipboardData" );
        c.sync();
        return true;
    }

    QDBusInterface klipper( "org.kde.klipper", "/klipper", "org.kde.klipper.klipper" );
    klipper.call( "clearClipboardHistory" );
    return true;
}
