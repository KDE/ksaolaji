#include "ksaolaji_cleaner_dummy.h"

#include <KDebug>
#include <KLocale>

KSAOLAJI_EXPORT_PLUGIN( CleanerDummy )

CleanerDummy::CleanerDummy( QObject* parent, const QVariantList& args )
: KSaoLaJi::CleanerPlugin(parent, args)
{
}

CleanerDummy::~CleanerDummy()
{
}

bool CleanerDummy::isThreadSafe() const
{
    return true;
}

QString CleanerDummy::uniqueName()
{
    return QString( "dummy_plugin" );
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
    kWarning() << "CleanerDummy::youlaji";
    return true;
}

bool CleanerDummy::saolaji()
{
    kWarning() << "CleanerDummy::saolaji";
    return true;
}
