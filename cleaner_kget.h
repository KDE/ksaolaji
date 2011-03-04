#ifndef CLEANER_KGET_H
#define CLEANER_KGET_H

#include "cleaner.h"

class CleanerKGet : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKGet( QObject* parent = 0 );
        virtual ~CleanerKGet();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KGET_H
