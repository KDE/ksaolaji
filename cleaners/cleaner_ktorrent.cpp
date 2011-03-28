#include "cleaner_ktorrent.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKTorrent::CleanerKTorrent()
{
}

CleanerKTorrent::~CleanerKTorrent()
{
}

QString CleanerKTorrent::uniqueName()
{
    return QString( "ktorrent_recent_files_and_last_save_dir" );
}

QString CleanerKTorrent::description()
{
    return i18n( "KTorrent recent files and last save directory" );
}

QString CleanerKTorrent::iconName()
{
    return QString( "ktorrent" );
}

bool CleanerKTorrent::youlaji()
{
    KConfig c( "ktorrentrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    KConfigGroup d( &c, "downloads" );
    return ( fs.exists() && fs.hasKey( "Recent Files" ) )
            || ( d.exists() && d.hasKey( "lastSaveDir" ) );
}

bool CleanerKTorrent::saolaji()
{
    KConfig c( "ktorrentrc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    KConfigGroup d( &c, "downloads" );
    d.deleteEntry( "lastSaveDir" );
    c.sync();
    return true;
}
