#include "cleaner_smplayer.h"

#include <KDebug>
#include <KLocale>

#include <QDir>
#include <QFile>
#include <QSettings>

CleanerSMPlayer::CleanerSMPlayer()
{
}

CleanerSMPlayer::~CleanerSMPlayer()
{
}

QString CleanerSMPlayer::uniqueName()
{
    return QString( "smplayer_recent_files_and_urls" );
}

QString CleanerSMPlayer::description()
{
    return i18n( "SMPlayer recent files and urls" );
}

QString CleanerSMPlayer::iconName()
{
    return QString( "smplayer" );
}

bool CleanerSMPlayer::youlaji()
{
    QString sf( QDir::homePath() + "/.config/smplayer/smplayer.ini" );
    QSettings st( sf, QSettings::NativeFormat );
    return st.value( "history/recents" ).isValid()
            || st.value( "history/urls" ).isValid()
            || !st.value( "directories/latest_dir" ).toString().isEmpty()
            || !st.value( "directories/last_dvd_directory" ).toString().isEmpty();
}

bool CleanerSMPlayer::saolaji()
{
    QString sf( QDir::homePath() + "/.config/smplayer/smplayer.ini" );
    QSettings st( sf, QSettings::NativeFormat );
    st.setValue( "history/recents", QVariant() );
    st.setValue( "history/urls", QVariant() );
    st.setValue( "directories/latest_dir", QString() );
    st.setValue( "directories/last_dvd_directory", QString() );
    st.sync();
    return true;
}
