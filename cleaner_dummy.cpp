#include "cleaner_dummy.h"

#include <KDebug>
#include <KLocale>

CleanerDummy::CleanerDummy( QObject* parent )
: Cleaner(parent)
{
}

CleanerDummy::~CleanerDummy()
{
}

QString CleanerDummy::description()
{
    return i18n( "Dummy = =!!!" );
}

QString CleanerDummy::iconName()
{
    return QString( "konqueror" );
}

bool CleanerDummy::youlaji()
{
//     kWarning() << "CleanerDummy::youlaji";
    return true;
}

bool CleanerDummy::saolaji()
{
    kWarning() << "CleanerDummy::saolaji";
    return true;
}
