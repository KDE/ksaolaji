#ifndef CLEANER_KRUNNER_H
#define CLEANER_KRUNNER_H

#include "cleaner.h"

class CleanerKRunner : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKRunner( QObject* parent = 0 );
        virtual ~CleanerKRunner();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KRUNNER_H
