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
