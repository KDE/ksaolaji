#ifndef CLEANER_FAVICON_H
#define CLEANER_FAVICON_H

#include "cleaner.h"

class CleanerFavicon : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerFavicon();
        virtual ~CleanerFavicon();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_FAVICON_H
