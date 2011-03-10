#ifndef CLEANER_KICKOFF_H
#define CLEANER_KICKOFF_H

#include "cleaner.h"

class CleanerKickoff : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKickoff();
        virtual ~CleanerKickoff();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KICKOFF_H
