#ifndef CLEANER_COOKIE_H
#define CLEANER_COOKIE_H

#include "cleaner.h"

class CleanerCookie : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerCookie( QObject* parent = 0 );
        virtual ~CleanerCookie();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_COOKIE_H
