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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KRUNNER_H
