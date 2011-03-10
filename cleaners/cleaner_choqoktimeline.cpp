#include "cleaner_choqoktimeline.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerChoqokTimeline::CleanerChoqokTimeline()
{
}

CleanerChoqokTimeline::~CleanerChoqokTimeline()
{
}

QString CleanerChoqokTimeline::uniqueName()
{
    return QString( "choqok_timeline_backup" );
}

QString CleanerChoqokTimeline::description()
{
    return i18n( "Choqok timeline backup" );
}

QString CleanerChoqokTimeline::iconName()
{
    return QString( "choqok" );
}

bool CleanerChoqokTimeline::youlaji()
{
    QDir cqdatadir( KStandardDirs::locateLocal( "data", "choqok" ) );
    QStringList namefilter;
    namefilter << "*_backuprc";
    QStringList backupfiles = cqdatadir.entryList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    return !backupfiles.isEmpty();
}

bool CleanerChoqokTimeline::saolaji()
{
    QDir cqdatadir( KStandardDirs::locateLocal( "data", "choqok" ) );
    QStringList namefilter;
    namefilter << "*_backuprc";
    QFileInfoList backupfiles = cqdatadir.entryInfoList( namefilter, QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = backupfiles.constBegin();
    QFileInfoList::ConstIterator end = backupfiles.constEnd();
    while ( it != end ) {
        QFile::remove( ( *it ).absoluteFilePath() );
        ++it;
    }
    return true;
}
