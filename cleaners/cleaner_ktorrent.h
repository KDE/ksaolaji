#ifndef CLEANER_KTORRENT_H
#define CLEANER_KTORRENT_H

#include "cleaner.h"

class CleanerKTorrent : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKTorrent();
        virtual ~CleanerKTorrent();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KTORRENT_H
