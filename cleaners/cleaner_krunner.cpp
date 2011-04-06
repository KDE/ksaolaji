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

#include "cleaner_krunner.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerKRunner::CleanerKRunner()
{
}

CleanerKRunner::~CleanerKRunner()
{
}

QString CleanerKRunner::uniqueName()
{
    return QString( "krunner_queries_and_history" );
}

QString CleanerKRunner::description()
{
    return i18n( "KRunner queries and history" );
}

QString CleanerKRunner::iconName()
{
    return QString( "system-run" );
}

bool CleanerKRunner::youlaji()
{
    if ( QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.krunner" ) ) {
        /// always true for running krunner query history
        return true;
    }

    KConfig c( "krunnerrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "General" );
    KConfigGroup prm( &c, "PlasmaRunnerManager" );
    return ( group.exists() && group.hasKey( "PastQueries" ) )
            || ( prm.exists() && prm.hasKey( "LaunchCounts" ) );
}

bool CleanerKRunner::saolaji()
{
    KConfig c( "krunnerrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "General" );
    group.deleteEntry( "PastQueries" );
    KConfigGroup prm( &c, "PlasmaRunnerManager" );
    prm.deleteEntry( "LaunchCounts" );
    c.sync();

    if ( QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.krunner" ) ) {
        QDBusInterface klipper( "org.kde.krunner", "/Interface", "org.kde.krunner.Interface" );
        klipper.call( "clearHistory" );
    }
    return true;
}
