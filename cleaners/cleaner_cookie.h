#ifndef CLEANER_COOKIE_H
#define CLEANER_COOKIE_H

#include "cleaner.h"

class CleanerCookie : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerCookie();
        virtual ~CleanerCookie();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_COOKIE_H
