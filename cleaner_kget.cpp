#include "cleaner_kget.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKGet::CleanerKGet( QObject* parent )
: Cleaner(parent)
{
}

CleanerKGet::~CleanerKGet()
{
}

QString CleanerKGet::description()
{
    return i18n( "KGet recent files and last directory" );
}

QString CleanerKGet::iconName()
{
    return QString( "kget" );
}

bool CleanerKGet::youlaji()
{
    KConfig c( "kgetrc" , KConfig::NoGlobals );
    KConfigGroup in( &c, "Internal" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( in.exists() && in.hasKey( "LastDirectory" ) ) || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKGet::saolaji()
{
    KConfig c( "kgetrc" , KConfig::NoGlobals );
    KConfigGroup in( &c, "Internal" );
    in.deleteEntry( "LastDirectory" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
