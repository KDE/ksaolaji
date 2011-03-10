#ifndef CLEANER_PLASMAWALLPAPER_H
#define CLEANER_PLASMAWALLPAPER_H

#include "cleaner.h"

class CleanerPlasmaWallpaper : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerPlasmaWallpaper();
        virtual ~CleanerPlasmaWallpaper();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_PLASMAWALLPAPER_H
