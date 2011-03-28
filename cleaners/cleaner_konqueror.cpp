#include "cleaner_konqueror.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKonqueror::CleanerKonqueror()
{
}

CleanerKonqueror::~CleanerKonqueror()
{
}

QString CleanerKonqueror::uniqueName()
{
    return QString( "konqueror_open_with_history_and_recent_files" );
}

QString CleanerKonqueror::description()
{
    return i18n( "Konqueror \"Open with\" history and recent files" );
}

QString CleanerKonqueror::iconName()
{
    return QString( "konqueror" );
}

bool CleanerKonqueror::youlaji()
{
    KConfig c( "konquerorrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( group.exists() && group.hasKey( "History" ) )
            || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKonqueror::saolaji()
{
    KConfig c( "konquerorrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    group.deleteEntry( "History" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
