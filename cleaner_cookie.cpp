#include "cleaner_cookie.h"

#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerCookie::CleanerCookie( QObject* parent )
: Cleaner(parent)
{
}

CleanerCookie::~CleanerCookie()
{
}

QString CleanerCookie::description()
{
    return i18n( "Saved site cookies" );
}

QString CleanerCookie::iconName()
{
    return QString( "preferences-web-browser-cookies" );
}

bool CleanerCookie::youlaji()
{
    return true;
}

bool CleanerCookie::saolaji()
{
    QDBusInterface kcookieserver( "org.kde.kded", "/modules/kcookiejar", "org.kde.KCookieServer" );
    kcookieserver.call( "deleteAllCookies" );
    return true;
}