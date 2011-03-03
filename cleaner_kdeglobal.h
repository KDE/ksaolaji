#ifndef CLEANER_KDEGLOBAL_H
#define CLEANER_KDEGLOBAL_H

#include "cleaner.h"

class CleanerKDEGlobal : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKDEGlobal( QObject* parent = 0 );
        virtual ~CleanerKDEGlobal();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KDEGLOBAL_H
