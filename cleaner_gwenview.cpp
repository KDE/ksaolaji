#include "cleaner_gwenview.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KStandardDirs>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerGwenview::CleanerGwenview( QObject* parent )
: Cleaner(parent)
{
}

CleanerGwenview::~CleanerGwenview()
{
}

QString CleanerGwenview::description()
{
    return i18n( "Gwenview recent files and urls" );
}

QString CleanerGwenview::iconName()
{
    return QString( "gwenview" );
}

bool CleanerGwenview::youlaji()
{
    QDir rfdir( KStandardDirs::locateLocal( "data", "gwenview/recentfolders" ) );
    QStringList rfs = rfdir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QDir rudir( KStandardDirs::locateLocal( "data", "gwenview/recenturls" ) );
    QStringList rus = rudir.entryList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    KConfig c( "gwenviewrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return !rfs.isEmpty() || !rus.isEmpty() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerGwenview::saolaji()
{
    KIO::Job* rfjob = KIO::del( KStandardDirs::locateLocal( "data", "gwenview/recentfolders" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( rfjob, 0 );

    KIO::Job* rujob = KIO::del( KStandardDirs::locateLocal( "data", "gwenview/recenturls" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( rujob, 0 );

    KConfig c( "gwenviewrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
