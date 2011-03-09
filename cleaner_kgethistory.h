#ifndef CLEANER_KGETHISTORY_H
#define CLEANER_KGETHISTORY_H

#include "cleaner.h"

class CleanerKGetHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKGetHistory();
        virtual ~CleanerKGetHistory();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KGETHISTORY_H
