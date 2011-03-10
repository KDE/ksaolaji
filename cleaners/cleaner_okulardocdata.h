#ifndef CLEANER_OKULARDOCDATA_H
#define CLEANER_OKULARDOCDATA_H

#include "cleaner.h"

class CleanerOkularDocData : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerOkularDocData();
        virtual ~CleanerOkularDocData();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_OKULARDOCDATA_H