/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>

 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    return i18n( "SMPlayer recent files and URLs" );
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
