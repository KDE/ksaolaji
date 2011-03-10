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

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KPIXMAPCACHE_H
