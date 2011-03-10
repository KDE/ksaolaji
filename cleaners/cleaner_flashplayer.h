#ifndef CLEANER_FLASHPLAYER_H
#define CLEANER_FLASHPLAYER_H

#include "cleaner.h"

class CleanerFlashPlayer : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerFlashPlayer();
        virtual ~CleanerFlashPlayer();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_FLASHPLAYER_H
