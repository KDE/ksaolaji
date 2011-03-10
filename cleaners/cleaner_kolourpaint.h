#ifndef CLEANER_KOLOURPAINT_H
#define CLEANER_KOLOURPAINT_H

#include "cleaner.h"

class CleanerKolourPaint : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKolourPaint();
        virtual ~CleanerKolourPaint();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KOLOURPAINT_H
