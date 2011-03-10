#ifndef CLEANER_RECENTDOC_H
#define CLEANER_RECENTDOC_H

#include "cleaner.h"

class CleanerRecentDoc : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerRecentDoc();
        virtual ~CleanerRecentDoc();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_RECENTDOC_H
