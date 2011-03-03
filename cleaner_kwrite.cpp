#include "cleaner_kwrite.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKWrite::CleanerKWrite( QObject* parent )
: Cleaner(parent)
{
}

CleanerKWrite::~CleanerKWrite()
{
}

QString CleanerKWrite::description()
{
    return i18n( "KWrite search replace patterns and recent files" );
}

QString CleanerKWrite::iconName()
{
    return QString( "accessories-text-editor" );
}

bool CleanerKWrite::youlaji()
{
    KConfig c( "kwriterc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    KConfigGroup srp( &c, "Kate View Defaults" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) )
    || ( srp.exists() && ( srp.hasKey( "Replacement Text History" ) || srp.hasKey( "Search Pattern History" ) ) );
}

bool CleanerKWrite::saolaji()
{
    KConfig c( "kwriterc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    KConfigGroup srp( &c, "Kate View Defaults" );
    srp.deleteEntry( "Replacement Text History" );
    srp.deleteEntry( "Search Pattern History" );
    c.sync();
    return true;
}
