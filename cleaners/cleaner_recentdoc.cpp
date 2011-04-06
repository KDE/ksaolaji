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

#include "cleaner_recentdoc.h"

#include <KDebug>
#include <KLocale>
#include <KRecentDocument>

CleanerRecentDoc::CleanerRecentDoc()
{
}

CleanerRecentDoc::~CleanerRecentDoc()
{
}

QString CleanerRecentDoc::uniqueName()
{
    return QString( "recent_accessed_documents" );
}

QString CleanerRecentDoc::description()
{
    return i18n( "Recent accessed documents" );
}

QString CleanerRecentDoc::iconName()
{
    return QString( "document-open-recent" );
}

bool CleanerRecentDoc::youlaji()
{
    return !KRecentDocument::recentDocuments().isEmpty();
}

bool CleanerRecentDoc::saolaji()
{
    KRecentDocument::clear();
    return true;
}
