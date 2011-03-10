#include "cleaner_krunner.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDBusInterface>

CleanerKRunner::CleanerKRunner()
{
}

CleanerKRunner::~CleanerKRunner()
{
}

QString CleanerKRunner::description()
{
    return i18n( "KRunner queries and history" );
}

QString CleanerKRunner::iconName()
{
    return QString( "system-run" );
}

bool CleanerKRunner::youlaji()
{
    if ( QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.krunner" ) ) {
        /// always true for running krunner query history
        return true;
    }

    KConfig c( "krunnerrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "General" );
    KConfigGroup prm( &c, "PlasmaRunnerManager" );
    return ( group.exists() && group.hasKey( "PastQueries" ) )
            || ( prm.exists() && prm.hasKey( "LaunchCounts" ) );
}

bool CleanerKRunner::saolaji()
{
    KConfig c( "krunnerrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "General" );
    group.deleteEntry( "PastQueries" );
    KConfigGroup prm( &c, "PlasmaRunnerManager" );
    prm.deleteEntry( "LaunchCounts" );
    c.sync();

    if ( QDBusConnection::sessionBus().interface()->isServiceRegistered( "org.kde.krunner" ) ) {
        QDBusInterface klipper( "org.kde.krunner", "/Interface", "org.kde.krunner.Interface" );
        klipper.call( "clearHistory" );
    }
    return true;
}
