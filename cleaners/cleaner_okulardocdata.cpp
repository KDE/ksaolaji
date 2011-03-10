#include "cleaner_okulardocdata.h"

#include <KDebug>
#include <KLocale>
#include <KStandardDirs>

#include <QDir>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>

CleanerOkularDocData::CleanerOkularDocData()
{
}

CleanerOkularDocData::~CleanerOkularDocData()
{
}

QString CleanerOkularDocData::uniqueName()
{
    return QString( "okular_orphaned_doc_notes_and_viewport_data" );
}

QString CleanerOkularDocData::description()
{
    return i18n( "Okular orphaned doc notes and viewport data" );
}

QString CleanerOkularDocData::iconName()
{
    return QString( "okular" );
}

bool CleanerOkularDocData::youlaji()
{
    QDir docdatadir( KStandardDirs::locateLocal( "data", "okular/docdata" ) );
    QFileInfoList datafileinfos = docdatadir.entryInfoList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = datafileinfos.constBegin();
    QFileInfoList::ConstIterator end = datafileinfos.constEnd();
    while ( it != end ) {
        QFile file( ( *it ).absoluteFilePath() );
        ++it;

        file.open( QIODevice::ReadOnly );
        QDomDocument doc( "documentInfo" );
        doc.setContent( &file );
        file.close();

        QDomElement root = doc.documentElement();
        if ( root.isNull() || root.tagName() != "documentInfo" )
            continue;

        QString docpath = root.attribute( "url" );
        if ( !QFile::exists( docpath ) )
            return true;
    }

    return false;
}

bool CleanerOkularDocData::saolaji()
{
    QDir docdatadir( KStandardDirs::locateLocal( "data", "okular/docdata" ) );
    QFileInfoList datafileinfos = docdatadir.entryInfoList( QDir::Files | QDir::NoSymLinks | QDir::Writable );
    QFileInfoList::ConstIterator it = datafileinfos.constBegin();
    QFileInfoList::ConstIterator end = datafileinfos.constEnd();
    while ( it != end ) {
        QFile file( ( *it ).absoluteFilePath() );
        ++it;

        file.open( QIODevice::ReadOnly );
        QDomDocument doc( "documentInfo" );
        doc.setContent( &file );
        file.close();

        QDomElement root = doc.documentElement();
        if ( root.isNull() || root.tagName() != "documentInfo" )
            continue;

        QString docpath = root.attribute( "url" );
        if ( !QFile::exists( docpath ) )
            file.remove();
    }

    return true;
}
