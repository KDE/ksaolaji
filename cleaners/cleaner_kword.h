#ifndef CLEANER_KWORD_H
#define CLEANER_KWORD_H

#include "cleaner.h"

class CleanerKWord : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKWord();
        virtual ~CleanerKWord();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KWORD_H
