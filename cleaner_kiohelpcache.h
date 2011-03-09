#ifndef CLEANER_KIOHELPCACHE_H
#define CLEANER_KIOHELPCACHE_H

#include "cleaner.h"

class CleanerKIOHelpCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKIOHelpCache();
        virtual ~CleanerKIOHelpCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KIOHELPCACHE_H
