#ifndef CLEANER_THUMBNAIL_H
#define CLEANER_THUMBNAIL_H

#include "cleaner.h"

class CleanerThumbnail : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerThumbnail();
        virtual ~CleanerThumbnail();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_THUMBNAIL_H