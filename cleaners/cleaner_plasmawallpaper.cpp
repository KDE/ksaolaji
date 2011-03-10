#include "cleaner_plasmawallpaper.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>
#include <KStandardDirs>

#include <QDir>
#include <QFile>

CleanerPlasmaWallpaper::CleanerPlasmaWallpaper()
{
}

CleanerPlasmaWallpaper::~CleanerPlasmaWallpaper()
{
}

QString CleanerPlasmaWallpaper::uniqueName()
{
    return QString( "plasma_wallpaper_image_cache" );
}

QString CleanerPlasmaWallpaper::description()
{
    return i18n( "Plasma wallpaper image cache" );
}

QString CleanerPlasmaWallpaper::iconName()
{
    return QString( "plasma-desktop" );
}

bool CleanerPlasmaWallpaper::youlaji()
{
    QDir snapdir( KStandardDirs::locateLocal( "cache", "plasma-wallpapers" ) );
    QStringList snapfs = snapdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !snapfs.isEmpty();
}

bool CleanerPlasmaWallpaper::saolaji()
{
    KIO::Job* sfjob = KIO::del( KStandardDirs::locateLocal( "cache", "plasma-wallpapers" ), KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( sfjob, 0 );
    return true;
}
