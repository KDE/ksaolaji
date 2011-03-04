#ifndef CLEANER_REKONQHISTORY_H
#define CLEANER_REKONQHISTORY_H

#include "cleaner.h"

class CleanerRekonqHistory : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerRekonqHistory( QObject* parent = 0 );
        virtual ~CleanerRekonqHistory();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_REKONQHISTORY_H
