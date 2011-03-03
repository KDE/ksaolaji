#ifndef CLEANER_KPIXMAPCACHE_H
#define CLEANER_KPIXMAPCACHE_H

#include "cleaner.h"

class CleanerKPixmapCache : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKPixmapCache( QObject* parent = 0 );
        virtual ~CleanerKPixmapCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KPIXMAPCACHE_H
