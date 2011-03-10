#ifndef CLEANER_VLC_H
#define CLEANER_VLC_H

#include "cleaner.h"

class CleanerVLC : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerVLC();
        virtual ~CleanerVLC();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_VLC_H
