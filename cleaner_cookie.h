#ifndef CLEANER_COOKIE_H
#define CLEANER_COOKIE_H

#include "cleaner.h"

class CleanerCookie : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerCookie();
        virtual ~CleanerCookie();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_COOKIE_H
