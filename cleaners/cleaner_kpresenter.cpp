#include "cleaner_kpresenter.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerKPresenter::CleanerKPresenter()
{
}

CleanerKPresenter::~CleanerKPresenter()
{
}

QString CleanerKPresenter::uniqueName()
{
    return QString( "kpresenter_recent_files_and_dirs" );
}

QString CleanerKPresenter::description()
{
    return i18n( "KPresenter recent files and dirs" );
}

QString CleanerKPresenter::iconName()
{
    return QString( "kpresenter" );
}

bool CleanerKPresenter::youlaji()
{
    KConfig c( "kpresenterrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    KConfigGroup group2( &c, "Recent Dirs" );
    KConfigGroup fs( &c, "KFileDialog Settings" );
    return group.exists() || group2.exists() || ( fs.exists() && fs.hasKey( "Recent Files" ) );
}

bool CleanerKPresenter::saolaji()
{
    KConfig c( "kpresenterrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "RecentFiles" );
    group.deleteGroup();
    KConfigGroup group2( &c, "Recent Dirs" );
    group2.deleteGroup();
    KConfigGroup fs( &c, "KFileDialog Settings" );
    fs.deleteEntry( "Recent Files" );
    c.sync();
    return true;
}
