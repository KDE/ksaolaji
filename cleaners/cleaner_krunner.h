#ifndef CLEANER_KRUNNER_H
#define CLEANER_KRUNNER_H

#include "cleaner.h"

class CleanerKRunner : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKRunner();
        virtual ~CleanerKRunner();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KRUNNER_H
