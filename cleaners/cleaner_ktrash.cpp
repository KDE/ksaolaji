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

#include "cleaner_ktrash.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>

#include <QByteArray>
#include <QDataStream>

CleanerKTrash::CleanerKTrash()
{
}

CleanerKTrash::~CleanerKTrash()
{
}

QString CleanerKTrash::uniqueName()
{
    return QString( "kde_trash_bin" );
}

QString CleanerKTrash::description()
{
    return i18n( "KDE trash bin" );
}

QString CleanerKTrash::iconName()
{
    return QString( "user-trash" );
}

bool CleanerKTrash::youlaji()
{
    KConfig c( "trashrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Status" );
    return !group.readEntry( "Empty", true );
}

bool CleanerKTrash::saolaji()
{
    QByteArray packedArgs;
    QDataStream stream( &packedArgs, QIODevice::WriteOnly );
    stream << (int)1;
    KIO::Job* job = KIO::special( KUrl( "trash:/" ), packedArgs );
    KIO::NetAccess::synchronousRun( job, 0 );
    return true;
}
