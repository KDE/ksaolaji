#ifndef CLEANER_KWRITE_H
#define CLEANER_KWRITE_H

#include "cleaner.h"

class CleanerKWrite : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKWrite( QObject* parent = 0 );
        virtual ~CleanerKWrite();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KWRITE_H
