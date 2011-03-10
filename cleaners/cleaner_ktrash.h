#ifndef CLEANER_KTRASH_H
#define CLEANER_KTRASH_H

#include "cleaner.h"

class CleanerKTrash : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKTrash();
        virtual ~CleanerKTrash();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KTRASH_H
