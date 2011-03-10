#include "cleaner_ktrash.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>

#include <QByteArray>
#include <QDataStream>

CleanerKTrash::CleanerKTrash()
{
}

CleanerKTrash::~CleanerKTrash()
{
}

QString CleanerKTrash::uniqueName()
{
    return QString( "kde_trash_bin" );
}

QString CleanerKTrash::description()
{
    return i18n( "KDE trash bin" );
}

QString CleanerKTrash::iconName()
{
    return QString( "user-trash" );
}

bool CleanerKTrash::youlaji()
{
    KConfig c( "trashrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Status" );
    return !group.readEntry( "Empty", true );
}

bool CleanerKTrash::saolaji()
{
    QByteArray packedArgs;
    QDataStream stream( &packedArgs, QIODevice::WriteOnly );
    stream << (int)1;
    KIO::Job* job = KIO::special( KUrl( "trash:/" ), packedArgs );
    KIO::NetAccess::synchronousRun( job, 0 );
    return true;
}
