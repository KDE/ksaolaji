#include "cleaner_kdeglobal.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKDEGlobal::CleanerKDEGlobal( QObject* parent )
: Cleaner(parent)
{
}

CleanerKDEGlobal::~CleanerKDEGlobal()
{
}

QString CleanerKDEGlobal::description()
{
    return i18n( "KDE global history items and recent urls" );
}

QString CleanerKDEGlobal::iconName()
{
    return QString( "start-here-kde" );
}

bool CleanerKDEGlobal::youlaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return ( group.exists() && group.hasKey( "History Items" ) )
            || ( fs.exists() && fs.hasKey( "Recent URLs" ) );
}

bool CleanerKDEGlobal::saolaji()
{
    KConfig c( "kdeglobals" , KConfig::NoGlobals );
    KConfigGroup group( &c, "DirSelect Dialog" );
    group.deleteEntry( "History Items" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent URLs" );
    c.sync();
    return true;
}