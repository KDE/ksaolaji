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

#include "cleaner_khtmlform.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KStandardDirs>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerKHTMLForm::CleanerKHTMLForm()
{
}

CleanerKHTMLForm::~CleanerKHTMLForm()
{
}

QString CleanerKHTMLForm::uniqueName()
{
    return QString( "khtml_form_completions" );
}

QString CleanerKHTMLForm::description()
{
    return i18n( "KHTML form completions" );
}

QString CleanerKHTMLForm::iconName()
{
    return QString( "preferences-web-browser-identification" );
}

bool CleanerKHTMLForm::youlaji()
{
    QString khtmldatadir = KStandardDirs::locateLocal( "data", "khtml" );
    return QFile::exists( khtmldatadir + "/formcompletions" );
}

bool CleanerKHTMLForm::saolaji()
{
    QString khtmldatadir = KStandardDirs::locateLocal( "data", "khtml" );
    QFile::remove( khtmldatadir + "/formcompletions" );
    return true;
}
