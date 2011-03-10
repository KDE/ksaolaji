#ifndef CLEANER_KPIXMAPCACHE_H
#define CLEANER_KPIXMAPCACHE_H

#include "cleaner.h"

class CleanerKPixmapCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKPixmapCache();
        virtual ~CleanerKPixmapCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KPIXMAPCACHE_H
