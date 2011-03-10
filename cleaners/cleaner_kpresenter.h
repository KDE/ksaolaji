#ifndef CLEANER_KPRESENTER_H
#define CLEANER_KPRESENTER_H

#include "cleaner.h"

class CleanerKPresenter : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKPresenter();
        virtual ~CleanerKPresenter();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KPRESENTER_H
