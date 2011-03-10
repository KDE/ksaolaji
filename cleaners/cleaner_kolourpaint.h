#ifndef CLEANER_KOLOURPAINT_H
#define CLEANER_KOLOURPAINT_H

#include "cleaner.h"

class CleanerKolourPaint : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKolourPaint();
        virtual ~CleanerKolourPaint();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KOLOURPAINT_H
