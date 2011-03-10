#include "cleaneritem.h"

#include "cleaner.h"

#include <KConfig>
#include <KConfigGroup>
#include <KGlobal>
#include <KSharedConfig>

CleanerItem::CleanerItem( KSaoLaJi::Cleaner* cleaner )
: m_cleaner(cleaner)
{
    m_youlaji = m_cleaner->youlaji();
    m_isChecked = false;
    KConfigGroup ucg = KGlobal::config()->group( "CleanerUseCount" );
    m_useCount = ucg.readEntry( m_cleaner->uniqueName(), 0 );
}

CleanerItem::~CleanerItem()
{
    KConfigGroup ucg = KGlobal::config()->group( "CleanerUseCount" );
    ucg.writeEntry( m_cleaner->uniqueName(), m_useCount );
    delete m_cleaner;
}

QString CleanerItem::description() const
{
    return m_cleaner->description();
}

QString CleanerItem::iconName() const
{
    return m_cleaner->iconName();
}

bool CleanerItem::youlaji( bool force )
{
    if ( force )
        m_youlaji = m_cleaner->youlaji();
    return m_youlaji;
}

bool CleanerItem::saolaji()
{
    ++m_useCount;
    return m_cleaner->saolaji();
}

bool CleanerItem::isChecked() const
{
    return m_isChecked;
}

void CleanerItem::setChecked( bool isChecked )
{
    m_isChecked = isChecked;
}

int CleanerItem::useCount() const
{
    return m_useCount;
}
