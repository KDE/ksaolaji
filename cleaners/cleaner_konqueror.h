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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KONQUEROR_H
