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
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_CHOQOKTIMELINE_H
