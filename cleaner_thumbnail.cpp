#include "cleaner_thumbnail.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerThumbnail::CleanerThumbnail()
{
}

CleanerThumbnail::~CleanerThumbnail()
{
}

QString CleanerThumbnail::description()
{
    return i18n( "Image thumbnails" );
}

QString CleanerThumbnail::iconName()
{
    return QString( "view-preview" );
}

bool CleanerThumbnail::youlaji()
{
    QDir ndir( QDir::homePath() + "/.thumbnails/normal" );
    QStringList nfs = ndir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir ldir( QDir::homePath() + "/.thumbnails/large" );
    QStringList lfs = ldir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir fdir( QDir::homePath() + "/.thumbnails/fail" );
    QStringList ffs = fdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !nfs.isEmpty() || !lfs.isEmpty() || !ffs.isEmpty();
}

bool CleanerThumbnail::saolaji()
{
    KIO::Job* nfjob = KIO::del( QDir::homePath() + "/.thumbnails/normal", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( nfjob, 0 );
    KIO::Job* lfjob = KIO::del( QDir::homePath() + "/.thumbnails/large", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( lfjob, 0 );
    KIO::Job* ffjob = KIO::del( QDir::homePath() + "/.thumbnails/fail", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( ffjob, 0 );
    return true;
}
