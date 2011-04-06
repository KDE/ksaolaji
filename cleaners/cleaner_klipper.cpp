#include "cleaner_klipper.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>
#include <QDBusReply>

CleanerKlipper::CleanerKlipper()
{
}

CleanerKlipper::~CleanerKlipper()
{
}

QString CleanerKlipper::uniqueName()
{
    return QString( "klipper_history" );
}

QString CleanerKlipper::description()
{
    return i18n( "Klipper history" );
}

QString CleanerKlipper::iconName()
{
    return QString( "klipper" );
}

bool CleanerKlipper::youlaji()
{
    if ( !QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.klipper" ) ) {
        KConfig c( "klipperrc" , KConfig::NoGlobals );
        KConfigGroup group( &c, "General" );
        return group.exists();
    }

    QDBusInterface klipper( "org.kde.klipper", "/klipper", "org.kde.klipper.klipper" );
    QDBusReply<QString> reply = klipper.call( "getClipboardContents" );
    return reply.isValid() && !reply.value().isEmpty();
}

bool CleanerKlipper::saolaji()
{
    if ( !QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.klipper" ) ) {
        KConfig c( "klipperrc" , KConfig::NoGlobals );
        KConfigGroup group( &c, "General" );
        group.deleteEntry( "ClipboardData" );
        c.sync();
        return true;
    }

    QDBusInterface klipper( "org.kde.klipper", "/klipper", "org.kde.klipper.klipper" );
    klipper.call( "clearClipboardHistory" );
    return true;
}
