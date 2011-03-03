#ifndef CLEANER_KMID_H
#define CLEANER_KMID_H

#include "cleaner.h"

class CleanerKMid : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKMid( QObject* parent = 0 );
        virtual ~CleanerKMid();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KMID_H
