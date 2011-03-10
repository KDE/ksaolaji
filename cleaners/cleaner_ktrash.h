#ifndef CLEANER_KTRASH_H
#define CLEANER_KTRASH_H

#include "cleaner.h"

class CleanerKTrash : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKTrash();
        virtual ~CleanerKTrash();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KTRASH_H
