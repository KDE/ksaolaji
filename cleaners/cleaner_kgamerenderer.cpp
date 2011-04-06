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

#include "cleaner_kgamerenderer.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKGameRenderer::CleanerKGameRenderer()
{
}

CleanerKGameRenderer::~CleanerKGameRenderer()
{
}

QString CleanerKGameRenderer::uniqueName()
{
    return QString( "kde_game_theme_cache" );
}

QString CleanerKGameRenderer::description()
{
    return i18n( "KDE game theme cache" );
}

QString CleanerKGameRenderer::iconName()
{
    return QString( "applications-games" );
}

bool CleanerKGameRenderer::youlaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "/" ) );
    QStringList namefilters;
    namefilters << "kgamerenderer-*";
    QStringList tcdirs = cachedir.entryList( namefilters, QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !tcdirs.isEmpty();
}

bool CleanerKGameRenderer::saolaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "/" ) );
    QStringList namefilters;
    namefilters << "kgamerenderer-*";
    QFileInfoList tcdirs = cachedir.entryInfoList( namefilters, QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QFileInfoList::ConstIterator it = tcdirs.constBegin();
    QFileInfoList::ConstIterator end = tcdirs.constEnd();
    while ( it != end ) {
        KIO::Job* helpjob = KIO::del( ( *it ).absoluteFilePath(), KIO::HideProgressInfo );
        KIO::NetAccess::synchronousRun( helpjob, 0 );
        ++it;
    }
    return true;
}
