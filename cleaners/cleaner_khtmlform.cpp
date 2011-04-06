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
