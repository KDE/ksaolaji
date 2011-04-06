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

#include "cleaner_kgethistory.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>
#include <KStandardDirs>
#include <Nepomuk/Resource>
#include <Nepomuk/ResourceManager>

#include <QFile>

CleanerKGetHistory::CleanerKGetHistory()
{
}

CleanerKGetHistory::~CleanerKGetHistory()
{
}

QString CleanerKGetHistory::uniqueName()
{
    return QString( "kget_xml_sqlite_nepomuk_transfer_history" );
}

QString CleanerKGetHistory::description()
{
    return i18n( "KGet XML/SQLite/Nepomuk transfer history" );
}

QString CleanerKGetHistory::iconName()
{
    return QString( "kget" );
}

bool CleanerKGetHistory::youlaji()
{
    QString xmlstore = KStandardDirs::locateLocal( "data", "kget/transferhistory.kgt" );
    QString sqlitestore = KStandardDirs::locateLocal( "data", "kget/transferhistory.db" );
    if ( Nepomuk::ResourceManager::instance()->initialized() ) {
        QList<Nepomuk::Resource> ress = Nepomuk::ResourceManager::instance()->allResourcesOfType(
            QUrl::fromEncoded( "http://nepomuk.kde.org/ontologies/2008/10/06/ndho#HistoryItem" )
        );
        return QFile::exists( xmlstore ) || QFile::exists( sqlitestore ) || !ress.isEmpty();
    }
    return QFile::exists( xmlstore ) || QFile::exists( sqlitestore );
}

bool CleanerKGetHistory::saolaji()
{
    QFile::remove( KStandardDirs::locateLocal( "data", "kget/transferhistory.kgt" ) );
    QFile::remove( KStandardDirs::locateLocal( "data", "kget/transferhistory.db" ) );
    if ( Nepomuk::ResourceManager::instance()->initialized() ) {
        QList<Nepomuk::Resource> ress = Nepomuk::ResourceManager::instance()->allResourcesOfType(
            QUrl::fromEncoded( "http://nepomuk.kde.org/ontologies/2008/10/06/ndho#HistoryItem" )
        );
        QList<Nepomuk::Resource>::Iterator it = ress.begin();
        QList<Nepomuk::Resource>::Iterator end = ress.end();
        while ( it != end ) {
            ( *it ).remove();
            ++it;
        }
    }
    return true;
}
