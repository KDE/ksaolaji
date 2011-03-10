#ifndef CLEANER_KAFFEINE_H
#define CLEANER_KAFFEINE_H

#include "cleaner.h"

class CleanerKaffeine : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKaffeine();
        virtual ~CleanerKaffeine();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KAFFEINE_H
