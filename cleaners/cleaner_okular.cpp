#include "cleaner_okular.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerOkular::CleanerOkular()
{
}

CleanerOkular::~CleanerOkular()
{
}

QString CleanerOkular::description()
{
    return i18n( "Okular recent files" );
}

QString CleanerOkular::iconName()
{
    return QString( "okular" );
}

bool CleanerOkular::youlaji()
{
    KConfig c( "okularrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerOkular::saolaji()
{
    KConfig c( "okularrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
