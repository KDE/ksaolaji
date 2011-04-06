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

#include "cleaner_ktorrentlog.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerKTorrentLog::CleanerKTorrentLog()
{
}

CleanerKTorrentLog::~CleanerKTorrentLog()
{
}

QString CleanerKTorrentLog::uniqueName()
{
    return QString( "ktorrent_log_files" );
}

QString CleanerKTorrentLog::description()
{
    return i18n( "KTorrent log files" );
}

QString CleanerKTorrentLog::iconName()
{
    return QString( "ktorrent" );
}

bool CleanerKTorrentLog::youlaji()
{
    QString ktdataenginefile = KStandardDirs::locateLocal( "data", "ktorrent/dataengine.log" );
    QDir ktdatadir( KStandardDirs::locateLocal( "data", "ktorrent" ) );
    QStringList namefilter;
    namefilter << "log" << "log-*.gz";
    QStringList logfiles = ktdatadir.entryList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return QFile::exists( ktdataenginefile ) || !logfiles.isEmpty();
}

bool CleanerKTorrentLog::saolaji()
{
    QString ktdataenginefile = KStandardDirs::locateLocal( "data", "ktorrent/dataengine.log" );
    QFile::remove( ktdataenginefile );

    QDir ktdatadir( KStandardDirs::locateLocal( "data", "ktorrent" ) );
    QStringList namefilter;
    namefilter << "log" << "log-*.gz";
    QFileInfoList logfiles = ktdatadir.entryInfoList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = logfiles.constBegin();
    QFileInfoList::ConstIterator end = logfiles.constEnd();
    while ( it != end ) {
        QFile::remove( ( *it ).absoluteFilePath() );
        ++it;
    }
    return true;
}
