#ifndef CLEANER_THUMBNAIL_H
#define CLEANER_THUMBNAIL_H

#include "cleaner.h"

class CleanerThumbnail : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerThumbnail();
        virtual ~CleanerThumbnail();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_THUMBNAIL_H
