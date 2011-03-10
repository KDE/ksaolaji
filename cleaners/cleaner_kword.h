#ifndef CLEANER_KWORD_H
#define CLEANER_KWORD_H

#include "cleaner.h"

class CleanerKWord : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKWord();
        virtual ~CleanerKWord();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KWORD_H
