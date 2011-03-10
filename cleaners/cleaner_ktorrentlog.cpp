#include "cleaner_ktorrentlog.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerKTorrentLog::CleanerKTorrentLog()
{
}

CleanerKTorrentLog::~CleanerKTorrentLog()
{
}

QString CleanerKTorrentLog::description()
{
    return i18n( "KTorrent log files" );
}

QString CleanerKTorrentLog::iconName()
{
    return QString( "ktorrent" );
}

bool CleanerKTorrentLog::youlaji()
{
    QString ktdataenginefile = KStandardDirs::locateLocal( "data", "ktorrent/dataengine.log" );
    QDir ktdatadir( KStandardDirs::locateLocal( "data", "ktorrent" ) );
    QStringList namefilter;
    namefilter << "log" << "log-*.gz";
    QStringList logfiles = ktdatadir.entryList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return QFile::exists( ktdataenginefile ) || !logfiles.isEmpty();
}

bool CleanerKTorrentLog::saolaji()
{
    QString ktdataenginefile = KStandardDirs::locateLocal( "data", "ktorrent/dataengine.log" );
    QFile::remove( ktdataenginefile );

    QDir ktdatadir( KStandardDirs::locateLocal( "data", "ktorrent" ) );
    QStringList namefilter;
    namefilter << "log" << "log-*.gz";
    QFileInfoList logfiles = ktdatadir.entryInfoList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = logfiles.constBegin();
    QFileInfoList::ConstIterator end = logfiles.constEnd();
    while ( it != end ) {
        QFile::remove( ( *it ).absoluteFilePath() );
        ++it;
    }
    return true;
}
