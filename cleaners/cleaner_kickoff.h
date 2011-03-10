#ifndef CLEANER_KICKOFF_H
#define CLEANER_KICKOFF_H

#include "cleaner.h"

class CleanerKickoff : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKickoff();
        virtual ~CleanerKickoff();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KICKOFF_H
