#ifndef CLEANER_KIOHELPCACHE_H
#define CLEANER_KIOHELPCACHE_H

#include "cleaner.h"

class CleanerKIOHelpCache : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKIOHelpCache();
        virtual ~CleanerKIOHelpCache();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KIOHELPCACHE_H
