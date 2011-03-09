#ifndef CLEANER_KMID_H
#define CLEANER_KMID_H

#include "cleaner.h"

class CleanerKMid : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKMid();
        virtual ~CleanerKMid();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KMID_H
