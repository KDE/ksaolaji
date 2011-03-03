#ifndef CLEANER_OKULAR_H
#define CLEANER_OKULAR_H

#include "cleaner.h"

class CleanerOkular : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerOkular( QObject* parent = 0 );
        virtual ~CleanerOkular();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_OKULAR_H
