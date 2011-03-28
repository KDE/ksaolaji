#include "cleaner_kdeglobal.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKDEGlobal::CleanerKDEGlobal()
{
}

CleanerKDEGlobal::~CleanerKDEGlobal()
{
}

QString CleanerKDEGlobal::uniqueName()
{
    return QString( "kde_global_history_items_and_recent_urls" );
}

QString CleanerKDEGlobal::description()
{
    return i18n( "KDE global history items and recent URLs" );
}

QString CleanerKDEGlobal::iconName()
{
    return QString( "start-here-kde" );
}

bool CleanerKDEGlobal::youlaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( group.exists() && group.hasKey( "History Items" ) )
            || ( fs.exists() && fs.hasKey( "Recent URLs" ) );
}

bool CleanerKDEGlobal::saolaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    group.deleteEntry( "History Items" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent URLs" );
    c.sync();
    return true;
}
