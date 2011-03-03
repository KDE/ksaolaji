#include "cleaner_kiohelpcache.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKIOHelpCache::CleanerKIOHelpCache( QObject* parent )
: Cleaner(parent)
{
}

CleanerKIOHelpCache::~CleanerKIOHelpCache()
{
}

QString CleanerKIOHelpCache::description()
{
    return i18n( "KDE help handbook cache" );
}

QString CleanerKIOHelpCache::iconName()
{
    return QString( "help-browser" );
}

bool CleanerKIOHelpCache::youlaji()
{
    QDir kiohelpdir( KStandardDirs::locateLocal( "cache", "kio_help" ) );
    QStringList kiohelpfs = kiohelpdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir helpdir( KStandardDirs::locateLocal( "cache", "help" ) );
    QStringList helpfs = helpdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !kiohelpfs.isEmpty() || !helpfs.isEmpty();
}

bool CleanerKIOHelpCache::saolaji()
{
    KIO::Job* kiohelpjob = KIO::del( KStandardDirs::locateLocal( "cache", "kio_help" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( kiohelpjob, 0 );
    KIO::Job* helpjob = KIO::del( KStandardDirs::locateLocal( "cache", "help" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( helpjob, 0 );
    return true;
}
