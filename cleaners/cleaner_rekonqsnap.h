#ifndef CLEANER_REKONQSNAP_H
#define CLEANER_REKONQSNAP_H

#include "cleaner.h"

class CleanerRekonqSnap : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerRekonqSnap();
        virtual ~CleanerRekonqSnap();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_REKONQSNAP_H
