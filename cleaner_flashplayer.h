#ifndef CLEANER_FLASHPLAYER_H
#define CLEANER_FLASHPLAYER_H

#include "cleaner.h"

class CleanerFlashPlayer : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerFlashPlayer( QObject* parent = 0 );
        virtual ~CleanerFlashPlayer();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_FLASHPLAYER_H
