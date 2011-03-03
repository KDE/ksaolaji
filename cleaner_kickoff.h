#ifndef CLEANER_KICKOFF_H
#define CLEANER_KICKOFF_H

#include "cleaner.h"

class CleanerKickoff : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKickoff( QObject* parent = 0 );
        virtual ~CleanerKickoff();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KICKOFF_H
