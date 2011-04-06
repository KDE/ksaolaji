#ifndef CLEANERJOB_H
#define CLEANERJOB_H

#include <ThreadWeaver/Job>

class CleanerItem;

class CleanerJob : public ThreadWeaver::Job
{
    public:
        explicit CleanerJob( CleanerItem* cleanerItem );
        virtual ~CleanerJob();
    protected:
        virtual void run();
    private:
        CleanerItem* m_cleanerItem;
};

#endif // CLEANERJOB_H
