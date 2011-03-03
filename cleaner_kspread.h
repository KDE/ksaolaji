#ifndef CLEANER_KSPREAD_H
#define CLEANER_KSPREAD_H

#include "cleaner.h"

class CleanerKSpread : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKSpread( QObject* parent = 0 );
        virtual ~CleanerKSpread();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KSPREAD_H
