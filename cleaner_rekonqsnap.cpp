#include "cleaner_rekonqsnap.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerRekonqSnap::CleanerRekonqSnap()
{
}

CleanerRekonqSnap::~CleanerRekonqSnap()
{
}

QString CleanerRekonqSnap::description()
{
    return i18n( "Rekonq webpage snapshot images" );
}

QString CleanerRekonqSnap::iconName()
{
    return QString( "rekonq" );
}

bool CleanerRekonqSnap::youlaji()
{
    QDir snapdir( KStandardDirs::locateLocal( "cache", "thumbs" ) );
    QStringList snapfs = snapdir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !snapfs.isEmpty();
}

bool CleanerRekonqSnap::saolaji()
{
    KIO::Job* sfjob = KIO::del( KStandardDirs::locateLocal( "cache", "thumbs" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( sfjob, 0 );
    return true;
}
