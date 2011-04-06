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

#include "cleaner_okulardocdata.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>

CleanerOkularDocData::CleanerOkularDocData()
{
}

CleanerOkularDocData::~CleanerOkularDocData()
{
}

QString CleanerOkularDocData::uniqueName()
{
    return QString( "okular_orphaned_doc_notes_and_viewport_data" );
}

QString CleanerOkularDocData::description()
{
    return i18n( "Okular orphaned document notes and viewport data" );
}

QString CleanerOkularDocData::iconName()
{
    return QString( "okular" );
}

bool CleanerOkularDocData::youlaji()
{
    QDir docdatadir( KStandardDirs::locateLocal( "data", "okular/docdata" ) );
    QFileInfoList datafileinfos = docdatadir.entryInfoList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = datafileinfos.constBegin();
    QFileInfoList::ConstIterator end = datafileinfos.constEnd();
    while ( it != end ) {
        QFile file( ( *it ).absoluteFilePath() );
        ++it;

        file.open( QIODevice::ReadOnly );
        QDomDocument doc( "documentInfo" );
        doc.setContent( &file );
        file.close();

        QDomElement root = doc.documentElement();
        if ( root.isNull() || root.tagName() != "documentInfo" )
            continue;

        QString docpath = root.attribute( "url" );
        if ( !QFile::exists( docpath ) )
            return true;
    }

    return false;
}

bool CleanerOkularDocData::saolaji()
{
    QDir docdatadir( KStandardDirs::locateLocal( "data", "okular/docdata" ) );
    QFileInfoList datafileinfos = docdatadir.entryInfoList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = datafileinfos.constBegin();
    QFileInfoList::ConstIterator end = datafileinfos.constEnd();
    while ( it != end ) {
        QFile file( ( *it ).absoluteFilePath() );
        ++it;

        file.open( QIODevice::ReadOnly );
        QDomDocument doc( "documentInfo" );
        doc.setContent( &file );
        file.close();

        QDomElement root = doc.documentElement();
        if ( root.isNull() || root.tagName() != "documentInfo" )
            continue;

        QString docpath = root.attribute( "url" );
        if ( !QFile::exists( docpath ) )
            file.remove();
    }

    return true;
}
