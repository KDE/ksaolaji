#include "cleaner_kword.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKWord::CleanerKWord()
{
}

CleanerKWord::~CleanerKWord()
{
}

QString CleanerKWord::uniqueName()
{
    return QString( "kword_recent_files_and_dirs" );
}

QString CleanerKWord::description()
{
    return i18n( "KWord recent files and dirs" );
}

QString CleanerKWord::iconName()
{
    return QString( "kword" );
}

bool CleanerKWord::youlaji()
{
    KConfig c( "kwordrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    KConfigGroup group2( &c, "Recent Dirs" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || group2.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKWord::saolaji()
{
    KConfig c( "kwordrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    group.deleteGroup();
    KConfigGroup group2( &c, "Recent Dirs" );
    group2.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
