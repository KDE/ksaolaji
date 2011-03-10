#include "cleaner_kate.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKate::CleanerKate()
{
}

CleanerKate::~CleanerKate()
{
}

QString CleanerKate::uniqueName()
{
    return QString( "kate_search_replace_patterns_and_recent_files" );
}

QString CleanerKate::description()
{
    return i18n( "Kate search replace patterns and recent files" );
}

QString CleanerKate::iconName()
{
    return QString( "kate" );
}

bool CleanerKate::youlaji()
{
    KConfig c( "katerc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    KConfigGroup kvd( &c, "Kate View Defaults" );
    return ( fs.exists() && fs.hasKey( "Recent Files" ) )
            || ( kvd.exists() && ( kvd.hasKey( "Replacement Text History" ) || kvd.hasKey( "Search Pattern History" ) ) );
}

bool CleanerKate::saolaji()
{
    KConfig c( "katerc" , KConfig::NoGlobals );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    KConfigGroup kvd( &c, "Kate View Defaults" );
    kvd.deleteEntry( "Replacement Text History" );
    kvd.deleteEntry( "Search Pattern History" );
    c.sync();
    return true;
}
