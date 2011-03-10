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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_FAVICON_H
