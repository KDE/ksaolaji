#include "cleaner_rekonqhistory.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QFile>

CleanerRekonqHistory::CleanerRekonqHistory( QObject* parent )
: Cleaner(parent)
{
}

CleanerRekonqHistory::~CleanerRekonqHistory()
{
}

QString CleanerRekonqHistory::description()
{
    return i18n( "Rekonq history" );
}

QString CleanerRekonqHistory::iconName()
{
    return QString( "rekonq" );
}

bool CleanerRekonqHistory::youlaji()
{
    return QFile::exists( KStandardDirs::locateLocal( "data", "rekonq/history" ) );
}

bool CleanerRekonqHistory::saolaji()
{
    QFile::remove( KStandardDirs::locateLocal( "data", "rekonq/history" ) );
    return true;
}
