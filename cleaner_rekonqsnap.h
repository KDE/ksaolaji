#ifndef CLEANER_REKONQSNAP_H
#define CLEANER_REKONQSNAP_H

#include "cleaner.h"

class CleanerRekonqSnap : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerRekonqSnap( QObject* parent = 0 );
        virtual ~CleanerRekonqSnap();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_REKONQSNAP_H
