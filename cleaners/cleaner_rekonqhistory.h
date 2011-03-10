#ifndef CLEANER_REKONQHISTORY_H
#define CLEANER_REKONQHISTORY_H

#include "cleaner.h"

class CleanerRekonqHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerRekonqHistory();
        virtual ~CleanerRekonqHistory();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_REKONQHISTORY_H
