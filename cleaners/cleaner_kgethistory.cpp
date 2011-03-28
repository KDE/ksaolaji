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
