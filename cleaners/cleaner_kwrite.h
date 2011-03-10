#ifndef CLEANER_KWRITE_H
#define CLEANER_KWRITE_H

#include "cleaner.h"

class CleanerKWrite : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKWrite();
        virtual ~CleanerKWrite();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KWRITE_H
