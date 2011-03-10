#ifndef CLEANER_KONQUEROR_H
#define CLEANER_KONQUEROR_H

#include "cleaner.h"

class CleanerKonqueror : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKonqueror();
        virtual ~CleanerKonqueror();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KONQUEROR_H
