#include "cleaner_konqlocbar.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKonqLocBar::CleanerKonqLocBar()
{
}

CleanerKonqLocBar::~CleanerKonqLocBar()
{
}

QString CleanerKonqLocBar::uniqueName()
{
    return QString( "konqueror_location_bar_contents_and_icon_cache" );
}

QString CleanerKonqLocBar::description()
{
    return i18n( "Konqueror location bar contents and icon cache" );
}

QString CleanerKonqLocBar::iconName()
{
    return QString( "konqueror" );
}

bool CleanerKonqLocBar::youlaji()
{
    KConfig c( "konq_history" , KConfig::NoGlobals );
    KConfigGroup lb( &c, "Location Bar" );
    return lb.exists() && ( lb.hasKey( "ComboContents" ) || lb.hasKey( "ComboIconCache" ) );
}

bool CleanerKonqLocBar::saolaji()
{
    KConfig c( "konq_history" , KConfig::NoGlobals );
    KConfigGroup lb( &c, "Location Bar" );
    lb.deleteEntry( "ComboContents" );
    lb.deleteEntry( "ComboIconCache" );
    c.sync();
    return true;
}
