#ifndef CLEANER_KATE_H
#define CLEANER_KATE_H

#include "cleaner.h"

class CleanerKate : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKate();
        virtual ~CleanerKate();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KATE_H
