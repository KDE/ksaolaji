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

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KATE_H
