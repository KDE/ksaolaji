#ifndef CLEANER_ARK_H
#define CLEANER_ARK_H

#include "cleaner.h"

class CleanerArk : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerArk( QObject* parent = 0 );
        virtual ~CleanerArk();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_ARK_H
