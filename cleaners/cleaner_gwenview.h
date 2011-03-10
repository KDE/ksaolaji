#ifndef CLEANER_GWENVIEW_H
#define CLEANER_GWENVIEW_H

#include "cleaner.h"

class CleanerGwenview : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerGwenview();
        virtual ~CleanerGwenview();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_GWENVIEW_H
