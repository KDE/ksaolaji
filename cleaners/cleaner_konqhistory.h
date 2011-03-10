#ifndef CLEANER_KONQHISTORY_H
#define CLEANER_KONQHISTORY_H

#include "cleaner.h"

class CleanerKonqHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKonqHistory();
        virtual ~CleanerKonqHistory();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KONQHISTORY_H
