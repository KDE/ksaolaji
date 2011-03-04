#ifndef CLEANER_KGETHISTORY_H
#define CLEANER_KGETHISTORY_H

#include "cleaner.h"

class CleanerKGetHistory : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKGetHistory( QObject* parent = 0 );
        virtual ~CleanerKGetHistory();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KGETHISTORY_H
