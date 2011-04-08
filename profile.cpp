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

#include "profile.h"

#include <KStandardDirs>

#include <QFile>
#include <QTextStream>

Profile::Profile( const QString& name )
: m_name(name)
{
    m_loaded = false;
}

Profile::~Profile()
{
}

QString Profile::name() const
{
    return m_name;
}

void Profile::load( bool force )
{
    if ( m_loaded && !force )
        return;

    QFile f( KStandardDirs::locateLocal( "appdata", "profiles/" ) + m_name );
    if ( !f.open( QIODevice::ReadOnly | QIODevice::Text ) )
        return;

    QTextStream in( &f );
    in.setCodec( "UTF-8" );
    while ( !in.atEnd() ) {
        m_checkedCleaners << in.readLine();
    }
    m_loaded = true;
}

void Profile::save() const
{
    QFile f( KStandardDirs::locateLocal( "appdata", "profiles/" ) + m_name );
    if ( !f.open( QIODevice::WriteOnly | QIODevice::Text ) )
        return;

    QTextStream out( &f );
    out.setCodec( "UTF-8" );
    QSet<QString>::ConstIterator it = m_checkedCleaners.constBegin();
    QSet<QString>::ConstIterator end = m_checkedCleaners.constEnd();
    while ( it != end ) {
        out << *it << '\n';
        ++it;
    }
}

bool Profile::contains( const QString& cleaner ) const
{
    return m_checkedCleaners.contains( cleaner );
}

void Profile::insert( const QString& cleaner )
{
    m_checkedCleaners.insert( cleaner );
}

void Profile::clear()
{
    m_checkedCleaners.clear();
}

void Profile::remove()
{
    QFile::remove( KStandardDirs::locateLocal( "appdata", "profiles/" ) + m_name );
    m_loaded = false;
}
