#ifndef CLEANER_VLC_H
#define CLEANER_VLC_H

#include "cleaner.h"

class CleanerVLC : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerVLC( QObject* parent = 0 );
        virtual ~CleanerVLC();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_VLC_H
