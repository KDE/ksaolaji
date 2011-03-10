#include "cleaner_kgamerenderer.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>

CleanerKGameRenderer::CleanerKGameRenderer()
{
}

CleanerKGameRenderer::~CleanerKGameRenderer()
{
}

QString CleanerKGameRenderer::description()
{
    return i18n( "KDE game theme cache" );
}

QString CleanerKGameRenderer::iconName()
{
    return QString( "applications-games" );
}

bool CleanerKGameRenderer::youlaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "/" ) );
    QStringList namefilters;
    namefilters << "kgamerenderer-*";
    QStringList tcdirs = cachedir.entryList( namefilters, QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !tcdirs.isEmpty();
}

bool CleanerKGameRenderer::saolaji()
{
    QDir cachedir( KStandardDirs::locateLocal( "cache", "/" ) );
    QStringList namefilters;
    namefilters << "kgamerenderer-*";
    QFileInfoList tcdirs = cachedir.entryInfoList( namefilters, QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QFileInfoList::ConstIterator it = tcdirs.constBegin();
    QFileInfoList::ConstIterator end = tcdirs.constEnd();
    while ( it != end ) {
        KIO::Job* helpjob = KIO::del( ( *it ).absoluteFilePath(), KIO::HideProgressInfo );
        KIO::NetAccess::synchronousRun( helpjob, 0 );
        ++it;
    }
    return true;
}
