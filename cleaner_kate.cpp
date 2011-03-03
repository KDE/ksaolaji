#include "cleaner_kate.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKate::CleanerKate( QObject* parent )
: Cleaner(parent)
{
}

CleanerKate::~CleanerKate()
{
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
