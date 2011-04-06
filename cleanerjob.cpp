#include "cleanerjob.h"

#include "cleaneritem.h"

#include <KDebug>

CleanerJob::CleanerJob( CleanerItem* cleanerItem )
: m_cleanerItem(cleanerItem)
{
}

CleanerJob::~CleanerJob()
{
}

void CleanerJob::run()
{
    kWarning() << "THREAD-SAFE CLEANER" << m_cleanerItem->description();
    m_cleanerItem->saolaji();
}
