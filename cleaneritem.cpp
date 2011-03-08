#include "cleaneritem.h"

#include "cleaner.h"

CleanerItem::CleanerItem( Cleaner* cleaner )
{
    m_cleaner = cleaner;
    m_youlaji = cleaner->youlaji();
    m_isChecked = false;
}

CleanerItem::~CleanerItem()
{
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
