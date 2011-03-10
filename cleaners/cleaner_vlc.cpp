#include "cleaner_vlc.h"

#include <KDebug>
#include <KLocale>

#include <QDir>
#include <QFile>
#include <QSettings>

CleanerVLC::CleanerVLC()
{
}

CleanerVLC::~CleanerVLC()
{
}

QString CleanerVLC::uniqueName()
{
    return QString( "vlc_recent_files_and_urls" );
}

QString CleanerVLC::description()
{
    return i18n( "VLC recent files and urls" );
}

QString CleanerVLC::iconName()
{
    return QString( "vlc" );
}

bool CleanerVLC::youlaji()
{
    QString sf( QDir::homePath() + "/.config/vlc/vlc-qt-interface.conf" );
    QSettings st( sf, QSettings::NativeFormat );
    return st.value( "RecentsMRL/list" ).isValid()
            || !st.value( "filedialog-path" ).toString().isEmpty();
}

bool CleanerVLC::saolaji()
{
    QString sf( QDir::homePath() + "/.config/vlc/vlc-qt-interface.conf" );
    QSettings st( sf, QSettings::NativeFormat );
    st.setValue( "RecentsMRL/list", QVariant() );
    st.setValue( "filedialog-path", QString() );
    st.sync();
    return true;
}
