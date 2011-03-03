#ifndef CLEANER_KRITA_H
#define CLEANER_KRITA_H

#include "cleaner.h"

class CleanerKrita : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKrita( QObject* parent = 0 );
        virtual ~CleanerKrita();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KRITA_H
