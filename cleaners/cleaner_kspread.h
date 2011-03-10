#ifndef CLEANER_KSPREAD_H
#define CLEANER_KSPREAD_H

#include "cleaner.h"

class CleanerKSpread : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKSpread();
        virtual ~CleanerKSpread();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KSPREAD_H
