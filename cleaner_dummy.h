#ifndef CLEANER_DUMMY_H
#define CLEANER_DUMMY_H

#include "cleaner.h"

class CleanerDummy : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerDummy( QObject* parent = 0 );
        virtual ~CleanerDummy();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_DUMMY_H
