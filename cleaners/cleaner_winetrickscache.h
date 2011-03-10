#ifndef CLEANER_WINETRICKSCACHE_H
#define CLEANER_WINETRICKSCACHE_H

#include "cleaner.h"

class CleanerWinetricksCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerWinetricksCache();
        virtual ~CleanerWinetricksCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_WINETRICKSCACHE_H
