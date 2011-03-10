#include "cleaner_kickoff.h"

#include <KDebug>
#include <KLocale>

#include <QDBusConnection>
#include <QDBusMessage>

CleanerKickoff::CleanerKickoff()
{
}

CleanerKickoff::~CleanerKickoff()
{
}

QString CleanerKickoff::description()
{
    return i18n( "Kickoff recent docs and apps" );
}

QString CleanerKickoff::iconName()
{
    return QString( "start-here-kde" );
}

bool CleanerKickoff::youlaji()
{
    return true;
}

bool CleanerKickoff::saolaji()
{
    QDBusMessage message = QDBusMessage::createSignal( "/kickoff/RecentAppDoc", "org.kde.plasma", "clearRecentDocumentsAndApplications" );
    QDBusConnection::sessionBus().send(message);
    return true;
}
