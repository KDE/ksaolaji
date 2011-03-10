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
