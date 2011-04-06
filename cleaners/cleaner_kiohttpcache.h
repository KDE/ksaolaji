#ifndef CLEANER_KIOHTTPCACHE_H
#define CLEANER_KIOHTTPCACHE_H

#include "cleaner.h"

class CleanerKIOHttpCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKIOHttpCache();
        virtual ~CleanerKIOHttpCache();
        virtual bool isThreadSafe() const;
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KIOHTTPCACHE_H
