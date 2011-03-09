#include "cleaner_ark.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerArk::CleanerArk()
{
}

CleanerArk::~CleanerArk()
{
}

QString CleanerArk::description()
{
    return i18n( "Ark recent files" );
}

QString CleanerArk::iconName()
{
    return QString( "utilities-file-archiver" );
}

bool CleanerArk::youlaji()
{
    KConfig c( "arkrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerArk::saolaji()
{
    KConfig c( "arkrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
