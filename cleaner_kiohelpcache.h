#ifndef CLEANER_KIOHELPCACHE_H
#define CLEANER_KIOHELPCACHE_H

#include "cleaner.h"

class CleanerKIOHelpCache : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKIOHelpCache( QObject* parent = 0 );
        virtual ~CleanerKIOHelpCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KIOHELPCACHE_H
