#include "cleaner_kiohttpcache.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QProcess>

CleanerKIOHttpCache::CleanerKIOHttpCache()
{
}

CleanerKIOHttpCache::~CleanerKIOHttpCache()
{
}

bool CleanerKIOHttpCache::isThreadSafe() const
{
    return true;
}

QString CleanerKIOHttpCache::uniqueName()
{
    return QString( "kde_http_cache" );
}

QString CleanerKIOHttpCache::description()
{
    return i18n( "KDE HTTP cache" );
}

QString CleanerKIOHttpCache::iconName()
{
    return QString( "preferences-web-browser-cache" );
}

bool CleanerKIOHttpCache::youlaji()
{
    /// TODO: any way to decide this ? --- nihui
    return true;
}

bool CleanerKIOHttpCache::saolaji()
{
    QString execfile = KStandardDirs::findExe( "kio_http_cache_cleaner" );
    QProcess::execute( execfile, QStringList() << "--clear-all" );
    return true;
}
