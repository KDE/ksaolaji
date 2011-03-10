#ifndef CLEANER_COOKIEPOLICY_H
#define CLEANER_COOKIEPOLICY_H

#include "cleaner.h"

class CleanerCookiePolicy : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerCookiePolicy();
        virtual ~CleanerCookiePolicy();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_COOKIEPOLICY_H
