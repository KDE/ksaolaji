#ifndef CLEANER_KSPREAD_H
#define CLEANER_KSPREAD_H

#include "cleaner.h"

class CleanerKSpread : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKSpread();
        virtual ~CleanerKSpread();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KSPREAD_H
