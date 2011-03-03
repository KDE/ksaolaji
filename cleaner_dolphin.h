#ifndef CLEANER_DOLPHIN_H
#define CLEANER_DOLPHIN_H

#include "cleaner.h"

class CleanerDolphin : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerDolphin( QObject* parent = 0 );
        virtual ~CleanerDolphin();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_DOLPHIN_H
