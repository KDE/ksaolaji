#include "cleaner_cookiepolicy.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerCookiePolicy::CleanerCookiePolicy()
{
}

CleanerCookiePolicy::~CleanerCookiePolicy()
{
}

QString CleanerCookiePolicy::description()
{
    return i18n( "Saved site cookie policies" );
}

QString CleanerCookiePolicy::iconName()
{
    return QString( "preferences-web-browser-cookies" );
}

bool CleanerCookiePolicy::youlaji()
{
    KConfig c( "kcookiejarrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Cookie Policy" );
    return group.exists() && group.hasKey( "CookieDomainAdvice" );
}

bool CleanerCookiePolicy::saolaji()
{
    KConfig c( "kcookiejarrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Cookie Policy" );
    group.deleteEntry( "CookieDomainAdvice" );
    c.sync();

    /// inform the cookie jar we pillaged it
    QDBusInterface kcookieserver( "org.kde.kded", "/modules/kcookiejar", "org.kde.KCookieServer" );
    kcookieserver.call( "reloadPolicy" );
    return true;
}
