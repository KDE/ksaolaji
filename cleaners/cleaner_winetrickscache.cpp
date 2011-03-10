#include "cleaner_winetrickscache.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerWinetricksCache::CleanerWinetricksCache()
{
}

CleanerWinetricksCache::~CleanerWinetricksCache()
{
}

QString CleanerWinetricksCache::description()
{
    return i18n( "Winetricks downloads cache" );
}

QString CleanerWinetricksCache::iconName()
{
    return QString( "wine" );
}

bool CleanerWinetricksCache::youlaji()
{
    QDir cachedir( QDir::homePath() + "/.winetrickscache" );
    QStringList kpcfs = cachedir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !kpcfs.isEmpty();
}

bool CleanerWinetricksCache::saolaji()
{
    KIO::Job* kpcjob = KIO::del( QDir::homePath() + "/.winetrickscache", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( kpcjob, 0 );
    return true;
}
