#ifndef CLEANER_OKULARDOCDATA_H
#define CLEANER_OKULARDOCDATA_H

#include "cleaner.h"

class CleanerOkularDocData : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerOkularDocData();
        virtual ~CleanerOkularDocData();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_OKULARDOCDATA_H
