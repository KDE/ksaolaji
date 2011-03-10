#ifndef CLEANER_DOLPHIN_H
#define CLEANER_DOLPHIN_H

#include "cleaner.h"

class CleanerDolphin : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerDolphin();
        virtual ~CleanerDolphin();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_DOLPHIN_H
