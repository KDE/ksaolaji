#ifndef CLEANER_KONQLOCBAR_H
#define CLEANER_KONQLOCBAR_H

#include "cleaner.h"

class CleanerKonqLocBar : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKonqLocBar();
        virtual ~CleanerKonqLocBar();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KONQLOCBAR_H
