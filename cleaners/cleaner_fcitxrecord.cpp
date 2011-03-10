#include "cleaner_fcitxrecord.h"

#include <KDebug>
#include <KLocale>

#include <QDir>
#include <QFile>

CleanerFcitxRecord::CleanerFcitxRecord()
{
}

CleanerFcitxRecord::~CleanerFcitxRecord()
{
}

QString CleanerFcitxRecord::description()
{
    return i18n( "Fcitx input record" );
}

QString CleanerFcitxRecord::iconName()
{
    return QString( "preferences-desktop-keyboard" );
}

bool CleanerFcitxRecord::youlaji()
{
    return QFile::exists( QDir::homePath() + "/.config/fcitx/record.dat" );
}

bool CleanerFcitxRecord::saolaji()
{
    QFile::remove( QDir::homePath() + "/.config/fcitx/record.dat" );
    return true;
}
