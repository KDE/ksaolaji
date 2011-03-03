#include "cleaner_krita.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKrita::CleanerKrita( QObject* parent )
: Cleaner(parent)
{
}

CleanerKrita::~CleanerKrita()
{
}

QString CleanerKrita::description()
{
    return i18n( "Krita recent files and dirs" );
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
