#ifndef CLEANER_KMID_H
#define CLEANER_KMID_H

#include "cleaner.h"

class CleanerKMid : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKMid();
        virtual ~CleanerKMid();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KMID_H
