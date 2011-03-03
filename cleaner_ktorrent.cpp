#include "cleaner_ktorrent.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKTorrent::CleanerKTorrent( QObject* parent )
: Cleaner(parent)
{
}

CleanerKTorrent::~CleanerKTorrent()
{
}

QString CleanerKTorrent::description()
{
    return i18n( "KTorrent recent files and last save dir" );
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
