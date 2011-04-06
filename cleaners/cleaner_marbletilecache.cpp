#include "cleaner_marbletilecache.h"

#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerMarbleTileCache::CleanerMarbleTileCache()
{
}

CleanerMarbleTileCache::~CleanerMarbleTileCache()
{
}

QString CleanerMarbleTileCache::uniqueName()
{
    return QString( "marble_tile_cache" );
}

QString CleanerMarbleTileCache::description()
{
    return i18n( "Marble tile cache" );
}

QString CleanerMarbleTileCache::iconName()
{
    return QString( "marble" );
}

bool CleanerMarbleTileCache::youlaji()
{
    QDBusConnectionInterface* i = QDBusConnection::sessionBus().interface();
    QDBusReply<QStringList> servicesReply = i->registeredServiceNames();
    QStringList services = servicesReply.value();
    QStringList::ConstIterator it = services.constBegin();
    QStringList::ConstIterator end = services.constEnd();
    while ( it != end ) {
        const QString service = *it;
        ++it;
        if ( service.startsWith( "org.kde.marble-" ) ) {
            /// always true for running marble
            return true;
        }
    }

    return false;
}

bool CleanerMarbleTileCache::saolaji()
{
    bool marbleRunning = false;
    QDBusConnectionInterface* i = QDBusConnection::sessionBus().interface();
    QDBusReply<QStringList> servicesReply = i->registeredServiceNames();
    QStringList services = servicesReply.value();
    QStringList::ConstIterator it = services.constBegin();
    QStringList::ConstIterator end = services.constEnd();
    while ( it != end ) {
        const QString service = *it;
        ++it;
        if ( service.startsWith( "org.kde.marble-" ) ) {
            marbleRunning = true;
            kWarning() << service;
            QDBusInterface marble( service, "/MarbleWidget", "org.kde.MarbleWidget" );
            kWarning() << marble.call( "clearPersistentTileCache" );
        }
    }

    if ( marbleRunning )
        return true;

    return true;
}
