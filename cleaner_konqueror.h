#ifndef CLEANER_KONQUEROR_H
#define CLEANER_KONQUEROR_H

#include "cleaner.h"

class CleanerKonqueror : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKonqueror( QObject* parent = 0 );
        virtual ~CleanerKonqueror();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KONQUEROR_H
