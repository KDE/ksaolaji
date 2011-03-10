#ifndef CLEANER_KIOHTTPCACHE_H
#define CLEANER_KIOHTTPCACHE_H

#include "cleaner.h"

class CleanerKIOHttpCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKIOHttpCache();
        virtual ~CleanerKIOHttpCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KIOHTTPCACHE_H
