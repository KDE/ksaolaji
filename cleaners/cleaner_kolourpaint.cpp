#include "cleaner_kolourpaint.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKolourPaint::CleanerKolourPaint()
{
}

CleanerKolourPaint::~CleanerKolourPaint()
{
}

QString CleanerKolourPaint::uniqueName()
{
    return QString( "kolourpaint_recent_files_and_image_size_info" );
}

QString CleanerKolourPaint::description()
{
    return i18n( "Kolourpaint recent files and image size info" );
}

QString CleanerKolourPaint::iconName()
{
    return QString( "kolourpaint" );
}

bool CleanerKolourPaint::youlaji()
{
    KConfig c( "kolourpaintrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    KConfigGroup gs( &c, "General Settings" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || ( gs.exists() && gs.hasKey( "Last Document Size" ) )
            || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKolourPaint::saolaji()
{
    KConfig c( "kolourpaintrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Recent Files" );
    group.deleteGroup();
    KConfigGroup gs( &c, "General Settings" );
    gs.deleteEntry( "Last Document Size" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
