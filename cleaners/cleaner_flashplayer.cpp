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
