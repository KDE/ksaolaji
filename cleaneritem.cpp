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

#include "cleaneritem.h"

#include "cleaner.h"

#include <KConfig>
#include <KConfigGroup>
#include <KGlobal>
#include <KSharedConfig>

CleanerItem::CleanerItem( KSaoLaJi::Cleaner* cleaner )
: m_cleaner(cleaner)
{
    m_youlaji = m_cleaner->youlaji();
    m_isChecked = false;
    KConfigGroup ucg = KGlobal::config()->group( "CleanerUseCount" );
    m_useCount = ucg.readEntry( m_cleaner->uniqueName(), 0 );
}

CleanerItem::~CleanerItem()
{
    KConfigGroup ucg = KGlobal::config()->group( "CleanerUseCount" );
    ucg.writeEntry( m_cleaner->uniqueName(), m_useCount );
    delete m_cleaner;
}

bool CleanerItem::isThreadSafe() const
{
    return m_cleaner->isThreadSafe();
}

QString CleanerItem::description() const
{
    return m_cleaner->description();
}

QString CleanerItem::iconName() const
{
    return m_cleaner->iconName();
}

bool CleanerItem::youlaji( bool force )
{
    if ( force )
        m_youlaji = m_cleaner->youlaji();
    return m_youlaji;
}

bool CleanerItem::saolaji()
{
    ++m_useCount;
    return m_cleaner->saolaji();
}

bool CleanerItem::isChecked() const
{
    return m_isChecked;
}

void CleanerItem::setChecked( bool isChecked )
{
    m_isChecked = isChecked;
}

int CleanerItem::useCount() const
{
    return m_useCount;
}
