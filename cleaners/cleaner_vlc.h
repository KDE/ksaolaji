#ifndef CLEANER_VLC_H
#define CLEANER_VLC_H

#include "cleaner.h"

class CleanerVLC : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerVLC();
        virtual ~CleanerVLC();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_VLC_H
