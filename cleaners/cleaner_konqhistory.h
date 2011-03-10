#ifndef CLEANER_KONQHISTORY_H
#define CLEANER_KONQHISTORY_H

#include "cleaner.h"

class CleanerKonqHistory : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKonqHistory();
        virtual ~CleanerKonqHistory();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KONQHISTORY_H
