/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>

 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

QString CleanerCookiePolicy::uniqueName()
{
    return QString( "saved_site_cookie_policies" );
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
