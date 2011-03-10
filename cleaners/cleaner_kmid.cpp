#include "cleaner_kmid.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKMid::CleanerKMid()
{
}

CleanerKMid::~CleanerKMid()
{
}

QString CleanerKMid::uniqueName()
{
    return QString( "kmid_recent_files" );
}

QString CleanerKMid::description()
{
    return i18n( "KMid recent files" );
}

QString CleanerKMid::iconName()
{
    return QString( "kmid" );
}

bool CleanerKMid::youlaji()
{
    KConfig c( "kmidrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKMid::saolaji()
{
    KConfig c( "kmidrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
