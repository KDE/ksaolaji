#include "cleaner_krita.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKrita::CleanerKrita()
{
}

CleanerKrita::~CleanerKrita()
{
}

QString CleanerKrita::uniqueName()
{
    return QString( "krita_recent_files_and_dirs" );
}

QString CleanerKrita::description()
{
    return i18n( "Krita recent files and directories" );
}

QString CleanerKrita::iconName()
{
    return QString( "krita" );
}

bool CleanerKrita::youlaji()
{
    KConfig c( "kritarc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    KConfigGroup group2( &c, "Recent Dirs" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || group2.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKrita::saolaji()
{
    KConfig c( "kritarc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    group.deleteGroup();
    KConfigGroup group2( &c, "Recent Dirs" );
    group2.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
