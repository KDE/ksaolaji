#ifndef CLEANER_KWRITE_H
#define CLEANER_KWRITE_H

#include "cleaner.h"

class CleanerKWrite : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKWrite();
        virtual ~CleanerKWrite();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KWRITE_H
