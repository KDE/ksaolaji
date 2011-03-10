#include "cleaner_kaffeine.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKaffeine::CleanerKaffeine()
{
}

CleanerKaffeine::~CleanerKaffeine()
{
}

QString CleanerKaffeine::uniqueName()
{
    return QString( "kaffeine_recent_files" );
}

QString CleanerKaffeine::description()
{
    return i18n( "Kaffeine recent files" );
}

QString CleanerKaffeine::iconName()
{
    return QString( "kaffeine" );
}

bool CleanerKaffeine::youlaji()
{
    KConfig c( "kaffeinerc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKaffeine::saolaji()
{
    KConfig c( "kaffeinerc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
