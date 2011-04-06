/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

bool CleanerFcitxRecord::isThreadSafe() const
{
    return true;
}

QString CleanerFcitxRecord::uniqueName()
{
    return QString( "fcitx_input_record" );
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
