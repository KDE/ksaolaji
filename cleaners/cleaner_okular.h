#ifndef CLEANER_OKULAR_H
#define CLEANER_OKULAR_H

#include "cleaner.h"

class CleanerOkular : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerOkular();
        virtual ~CleanerOkular();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_OKULAR_H
