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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_NEPOMUKCACHE_H
