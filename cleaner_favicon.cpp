#include "cleaner_favicon.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerFavicon::CleanerFavicon()
{
}

CleanerFavicon::~CleanerFavicon()
{
}

QString CleanerFavicon::description()
{
    return i18n( "Cached site favicons" );
}

QString CleanerFavicon::iconName()
{
    return QString( "bookmarks" );
}

bool CleanerFavicon::youlaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "favicons" ) );
    QStringList faviconfs = cachedir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !faviconfs.isEmpty();
}

bool CleanerFavicon::saolaji()
{
    KIO::Job* faviconjob = KIO::del( KStandardDirs::locateLocal( "cache", "favicons" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( faviconjob, 0 );
    return true;
}
