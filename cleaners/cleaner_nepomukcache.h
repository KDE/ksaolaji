#ifndef CLEANER_NEPOMUKCACHE_H
#define CLEANER_NEPOMUKCACHE_H

#include "cleaner.h"

class CleanerNepomukCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerNepomukCache();
        virtual ~CleanerNepomukCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_NEPOMUKCACHE_H
