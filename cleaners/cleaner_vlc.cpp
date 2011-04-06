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
    return i18n( "VLC recent files and URLs" );
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
