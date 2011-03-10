#include "cleaner_kpixmapcache.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKPixmapCache::CleanerKPixmapCache()
{
}

CleanerKPixmapCache::~CleanerKPixmapCache()
{
}

QString CleanerKPixmapCache::uniqueName()
{
    return QString( "kde_pixmap_cache" );
}

QString CleanerKPixmapCache::description()
{
    return i18n( "KDE pixmap cache" );
}

QString CleanerKPixmapCache::iconName()
{
    return QString( "preferences-desktop-icons" );
}

bool CleanerKPixmapCache::youlaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "kpc" ) );
    QStringList kpcfs = cachedir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !kpcfs.isEmpty();
}

bool CleanerKPixmapCache::saolaji()
{
    KIO::Job* kpcjob = KIO::del( KStandardDirs::locateLocal( "cache", "kpc" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( kpcjob, 0 );
    return true;
}
