#ifndef CLEANER_KDEGLOBAL_H
#define CLEANER_KDEGLOBAL_H

#include "cleaner.h"

class CleanerKDEGlobal : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKDEGlobal();
        virtual ~CleanerKDEGlobal();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KDEGLOBAL_H
