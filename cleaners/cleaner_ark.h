#ifndef CLEANER_ARK_H
#define CLEANER_ARK_H

#include "cleaner.h"

class CleanerArk : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerArk();
        virtual ~CleanerArk();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_ARK_H
