#include "cleaner_kross.h"

#include <kross/core/action.h>

CleanerKross::CleanerKross( QString file, QObject* parent )
: Cleaner(parent)
{
    m_action = new Kross::Action( this, "KrossScript" );
    m_action->setFile( file );
    m_action->trigger();
    m_description = m_action->callFunction( "description" ).toString();
    m_iconName = m_action->callFunction( "iconName" ).toString();
}

CleanerKross::~CleanerKross()
{
}

QString CleanerKross::description()
{
    return m_description;
}

QString CleanerKross::iconName()
{
    return m_iconName;
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
