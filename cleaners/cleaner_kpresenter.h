#ifndef CLEANER_KPRESENTER_H
#define CLEANER_KPRESENTER_H

#include "cleaner.h"

class CleanerKPresenter : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKPresenter();
        virtual ~CleanerKPresenter();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KPRESENTER_H
