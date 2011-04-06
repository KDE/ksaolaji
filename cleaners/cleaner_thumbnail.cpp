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

#include "cleaner_thumbnail.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerThumbnail::CleanerThumbnail()
{
}

CleanerThumbnail::~CleanerThumbnail()
{
}

QString CleanerThumbnail::uniqueName()
{
    return QString( "image_thumbnails" );
}

QString CleanerThumbnail::description()
{
    return i18n( "Image thumbnails" );
}

QString CleanerThumbnail::iconName()
{
    return QString( "view-preview" );
}

bool CleanerThumbnail::youlaji()
{
    QDir ndir( QDir::homePath() + "/.thumbnails/normal" );
    QStringList nfs = ndir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir ldir( QDir::homePath() + "/.thumbnails/large" );
    QStringList lfs = ldir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir fdir( QDir::homePath() + "/.thumbnails/fail" );
    QStringList ffs = fdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !nfs.isEmpty() || !lfs.isEmpty() || !ffs.isEmpty();
}

bool CleanerThumbnail::saolaji()
{
    KIO::Job* nfjob = KIO::del( QDir::homePath() + "/.thumbnails/normal", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( nfjob, 0 );
    KIO::Job* lfjob = KIO::del( QDir::homePath() + "/.thumbnails/large", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( lfjob, 0 );
    KIO::Job* ffjob = KIO::del( QDir::homePath() + "/.thumbnails/fail", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( ffjob, 0 );
    return true;
}
