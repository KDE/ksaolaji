#ifndef CLEANER_PLASMAWALLPAPER_H
#define CLEANER_PLASMAWALLPAPER_H

#include "cleaner.h"

class CleanerPlasmaWallpaper : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerPlasmaWallpaper( QObject* parent = 0 );
        virtual ~CleanerPlasmaWallpaper();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_PLASMAWALLPAPER_H
