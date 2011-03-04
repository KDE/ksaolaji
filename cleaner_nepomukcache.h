#ifndef CLEANER_NEPOMUKCACHE_H
#define CLEANER_NEPOMUKCACHE_H

#include "cleaner.h"

class CleanerNepomukCache : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerNepomukCache( QObject* parent = 0 );
        virtual ~CleanerNepomukCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_NEPOMUKCACHE_H
