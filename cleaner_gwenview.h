#ifndef CLEANER_GWENVIEW_H
#define CLEANER_GWENVIEW_H

#include "cleaner.h"

class CleanerGwenview : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerGwenview();
        virtual ~CleanerGwenview();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_GWENVIEW_H
