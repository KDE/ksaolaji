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

#include "cleaner_kickoff.h"

#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusMessage>

CleanerKickoff::CleanerKickoff()
{
}

CleanerKickoff::~CleanerKickoff()
{
}

QString CleanerKickoff::uniqueName()
{
    return QString( "kickoff_recent_docs_and_apps" );
}

QString CleanerKickoff::description()
{
    return i18n( "Kickoff recent documents and applications" );
}

QString CleanerKickoff::iconName()
{
    return QString( "start-here-kde" );
}

bool CleanerKickoff::youlaji()
{
    return true;
}

bool CleanerKickoff::saolaji()
{
    QDBusMessage message = QDBusMessage::createSignal( "/kickoff/RecentAppDoc", "org.kde.plasma", "clearRecentDocumentsAndApplications" );
    QDBusConnection::sessionBus().send(message);
    return true;
}
