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

#include "cleaner_rekonqhistory.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QFile>

CleanerRekonqHistory::CleanerRekonqHistory()
{
}

CleanerRekonqHistory::~CleanerRekonqHistory()
{
}

QString CleanerRekonqHistory::uniqueName()
{
    return QString( "rekonq_history" );
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
