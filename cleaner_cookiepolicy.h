#ifndef CLEANER_COOKIEPOLICY_H
#define CLEANER_COOKIEPOLICY_H

#include "cleaner.h"

class CleanerCookiePolicy : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerCookiePolicy( QObject* parent = 0 );
        virtual ~CleanerCookiePolicy();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_COOKIEPOLICY_H
