#include "cleaner_konqhistory.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QFile>

CleanerKonqHistory::CleanerKonqHistory( QObject* parent )
: Cleaner(parent)
{
}

CleanerKonqHistory::~CleanerKonqHistory()
{
}

QString CleanerKonqHistory::description()
{
    return i18n( "Konqueror history" );
}

QString CleanerKonqHistory::iconName()
{
    return QString( "view-history" );
}

bool CleanerKonqHistory::youlaji()
{
    return QFile::exists( KStandardDirs::locateLocal( "data", "konqueror/konq_history" ) );
}

bool CleanerKonqHistory::saolaji()
{
    QDBusMessage message = QDBusMessage::createSignal( "/KonqHistoryManager", "org.kde.Konqueror.HistoryManager", "notifyClear" );
    QDBusConnection::sessionBus().send( message );
    QFile::remove( KStandardDirs::locateLocal( "data", "konqueror/konq_history" ) );
    return true;
}
