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

#include "cleaner_flashplayer.h"

#include <KDebug>
#include <KLocale>
#include <KIO/DeleteJob>
#include <KIO/Job>
#include <KIO/NetAccess>
#include <KUrl>

#include <QDir>
#include <QFile>

CleanerFlashPlayer::CleanerFlashPlayer()
{
}

CleanerFlashPlayer::~CleanerFlashPlayer()
{
}

QString CleanerFlashPlayer::uniqueName()
{
    return QString( "adobe_flash_player_site_cookies_and_settings" );
}

QString CleanerFlashPlayer::description()
{
    return i18n( "Adobe Flash player site cookies and settings" );
}

QString CleanerFlashPlayer::iconName()
{
    return QString( "flash" );
}

bool CleanerFlashPlayer::youlaji()
{
    QDir afdir( QDir::homePath() + "/.adobe/Flash_Player" );
    QStringList afs = afdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    QDir mfdir( QDir::homePath() + "/.macromedia/Flash_Player" );
    QStringList mfs = mfdir.entryList( QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Writable );
    return !afs.isEmpty() || !mfs.isEmpty();
}

bool CleanerFlashPlayer::saolaji()
{
    KIO::Job* afjob = KIO::del( QDir::homePath() + "/.adobe/Flash_Player", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( afjob, 0 );
    KIO::Job* mfjob = KIO::del( QDir::homePath() + "/.macromedia/Flash_Player", KIO::HideProgressInfo );
    KIO::NetAccess::synchronousRun( mfjob, 0 );
    return true;
}
