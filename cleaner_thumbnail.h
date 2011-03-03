#ifndef CLEANER_THUMBNAIL_H
#define CLEANER_THUMBNAIL_H

#include "cleaner.h"

class CleanerThumbnail : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerThumbnail( QObject* parent = 0 );
        virtual ~CleanerThumbnail();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_THUMBNAIL_H
