#ifndef CLEANER_SMPLAYER_H
#define CLEANER_SMPLAYER_H

#include "cleaner.h"

class CleanerSMPlayer : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerSMPlayer( QObject* parent = 0 );
        virtual ~CleanerSMPlayer();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_SMPLAYER_H
