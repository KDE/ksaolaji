#ifndef CLEANER_KIOHTTPCACHE_H
#define CLEANER_KIOHTTPCACHE_H

#include "cleaner.h"

class CleanerKIOHttpCache : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKIOHttpCache( QObject* parent = 0 );
        virtual ~CleanerKIOHttpCache();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KIOHTTPCACHE_H
