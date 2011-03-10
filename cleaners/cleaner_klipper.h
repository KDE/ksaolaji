#ifndef CLEANER_KLIPPER_H
#define CLEANER_KLIPPER_H

#include "cleaner.h"

class CleanerKlipper : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKlipper();
        virtual ~CleanerKlipper();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KLIPPER_H
