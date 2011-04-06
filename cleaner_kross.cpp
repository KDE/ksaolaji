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

#include "cleaner_kross.h"

#include <kross/core/action.h>

CleanerKross::CleanerKross( const QString& file )
{
    m_action = new Kross::Action( 0, "KrossScript" );
    m_action->setFile( file );
    m_action->trigger();
    m_uniqueName = m_action->callFunction( "uniqueName" ).toString();
    m_description = m_action->callFunction( "description" ).toString();
    m_iconName = m_action->callFunction( "iconName" ).toString();
}

CleanerKross::~CleanerKross()
{
    delete m_action;
}

QString CleanerKross::uniqueName()
{
    return m_uniqueName;
}

QString CleanerKross::description()
{
    return m_description;
}

QString CleanerKross::iconName()
{
    return m_iconName;
}

bool CleanerKross::youlaji()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "youlaji" );
    return ret.toBool();
}

bool CleanerKross::saolaji()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "saolaji" );
    return ret.toBool();
}
