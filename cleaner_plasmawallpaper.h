#ifndef CLEANER_PLASMAWALLPAPER_H
#define CLEANER_PLASMAWALLPAPER_H

#include "cleaner.h"

class CleanerPlasmaWallpaper : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerPlasmaWallpaper();
        virtual ~CleanerPlasmaWallpaper();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_PLASMAWALLPAPER_H
