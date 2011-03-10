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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_WINETRICKSCACHE_H
