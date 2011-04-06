#ifndef CLEANER_MARBLETILECACHE_H
#define CLEANER_MARBLETILECACHE_H

#include "cleaner.h"

class CleanerMarbleTileCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerMarbleTileCache();
        virtual ~CleanerMarbleTileCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_MARBLETILECACHE_H
