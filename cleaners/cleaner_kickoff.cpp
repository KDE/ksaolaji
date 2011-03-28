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

QString CleanerKickoff::uniqueName()
{
    return QString( "kickoff_recent_docs_and_apps" );
}

QString CleanerKickoff::description()
{
    return i18n( "Kickoff recent documents and applications" );
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
