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

#include "cleaner_dolphin.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerDolphin::CleanerDolphin()
{
}

CleanerDolphin::~CleanerDolphin()
{
}

QString CleanerDolphin::uniqueName()
{
    return QString( "dolphin_open_with_history" );
}

QString CleanerDolphin::description()
{
    return i18n( "Dolphin \"Open with\" history" );
}

QString CleanerDolphin::iconName()
{
    return QString( "system-file-manager" );
}

bool CleanerDolphin::youlaji()
{
    KConfig c( "dolphinrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    return group.exists() && group.hasKey( "History" );
}

bool CleanerDolphin::saolaji()
{
    KConfig c( "dolphinrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    group.deleteEntry( "History" );
    c.sync();
    return true;
}
