#ifndef CLEANER_CHOQOKTIMELINE_H
#define CLEANER_CHOQOKTIMELINE_H

#include "cleaner.h"

class CleanerChoqokTimeline : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerChoqokTimeline();
        virtual ~CleanerChoqokTimeline();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_CHOQOKTIMELINE_H
