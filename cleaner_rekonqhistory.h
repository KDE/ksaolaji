#ifndef CLEANER_REKONQHISTORY_H
#define CLEANER_REKONQHISTORY_H

#include "cleaner.h"

class CleanerRekonqHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerRekonqHistory();
        virtual ~CleanerRekonqHistory();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_REKONQHISTORY_H
