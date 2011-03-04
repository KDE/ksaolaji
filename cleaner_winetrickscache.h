#ifndef CLEANER_WINETRICKSCACHE_H
#define CLEANER_WINETRICKSCACHE_H

#include "cleaner.h"

class CleanerWinetricksCache : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerWinetricksCache( QObject* parent = 0 );
        virtual ~CleanerWinetricksCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_WINETRICKSCACHE_H
