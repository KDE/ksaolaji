#include "cleaner_kspread.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKSpread::CleanerKSpread()
{
}

CleanerKSpread::~CleanerKSpread()
{
}

QString CleanerKSpread::uniqueName()
{
    return QString( "kspread_recent_files_and_dirs" );
}

QString CleanerKSpread::description()
{
    return i18n( "KSpread recent files and dirs" );
}

QString CleanerKSpread::iconName()
{
    return QString( "kspread" );
}

bool CleanerKSpread::youlaji()
{
    KConfig c( "kspreadrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    KConfigGroup group2( &c, "Recent Dirs" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || group2.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKSpread::saolaji()
{
    KConfig c( "kspreadrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    group.deleteGroup();
    KConfigGroup group2( &c, "Recent Dirs" );
    group2.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
