#ifndef CLEANER_KGET_H
#define CLEANER_KGET_H

#include "cleaner.h"

class CleanerKGet : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKGet();
        virtual ~CleanerKGet();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KGET_H
