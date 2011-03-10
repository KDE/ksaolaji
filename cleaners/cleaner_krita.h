#ifndef CLEANER_KRITA_H
#define CLEANER_KRITA_H

#include "cleaner.h"

class CleanerKrita : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKrita();
        virtual ~CleanerKrita();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KRITA_H
