#ifndef CLEANER_SMPLAYER_H
#define CLEANER_SMPLAYER_H

#include "cleaner.h"

class CleanerSMPlayer : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerSMPlayer();
        virtual ~CleanerSMPlayer();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_SMPLAYER_H
