#include "cleaner_dolphin.h"

#include <KConfig>
#include <KConfigGroup>
#include <KDebug>
#include <KLocale>

CleanerDolphin::CleanerDolphin()
{
}

CleanerDolphin::~CleanerDolphin()
{
}

QString CleanerDolphin::uniqueName()
{
    return QString( "dolphin_open_with_history" );
}

QString CleanerDolphin::description()
{
    return i18n( "Dolphin open-with history" );
}

QString CleanerDolphin::iconName()
{
    return QString( "system-file-manager" );
}

bool CleanerDolphin::youlaji()
{
    KConfig c( "dolphinrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    return group.exists() && group.hasKey( "History" );
}

bool CleanerDolphin::saolaji()
{
    KConfig c( "dolphinrc" , KConfig::NoGlobals );
    KConfigGroup group( &c, "Open-with settings" );
    group.deleteEntry( "History" );
    c.sync();
    return true;
}
