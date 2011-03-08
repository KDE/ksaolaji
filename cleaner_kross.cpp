#include "cleaner_kross.h"

#include <kross/core/action.h>

CleanerKross::CleanerKross( QString file, QObject* parent )
: Cleaner(parent)
{
    m_action = new Kross::Action( this, "KrossScript" );
    m_action->setFile( file );
}

CleanerKross::~CleanerKross()
{
}

QString CleanerKross::description()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "description" );
    return ret.toString();
}

QString CleanerKross::iconName()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "iconName" );
    return ret.toString();
}

bool CleanerKross::youlaji()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "youlaji" );
    return ret.toBool();
}

bool CleanerKross::saolaji()
{
    m_action->trigger();
    QVariant ret = m_action->callFunction( "saolaji" );
    return ret.toBool();
}
