#ifndef CLEANER_FAVICON_H
#define CLEANER_FAVICON_H

#include "cleaner.h"

class CleanerFavicon : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerFavicon( QObject* parent = 0 );
        virtual ~CleanerFavicon();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_FAVICON_H
