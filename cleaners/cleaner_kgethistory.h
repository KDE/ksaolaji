#ifndef CLEANER_KGETHISTORY_H
#define CLEANER_KGETHISTORY_H

#include "cleaner.h"

class CleanerKGetHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKGetHistory();
        virtual ~CleanerKGetHistory();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KGETHISTORY_H
