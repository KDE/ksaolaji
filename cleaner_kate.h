#ifndef CLEANER_KATE_H
#define CLEANER_KATE_H

#include "cleaner.h"

class CleanerKate : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKate( QObject* parent = 0 );
        virtual ~CleanerKate();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KATE_H
