#ifndef CLEANER_KTORRENTLOG_H
#define CLEANER_KTORRENTLOG_H

#include "cleaner.h"

class CleanerKTorrentLog : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKTorrentLog( QObject* parent = 0 );
        virtual ~CleanerKTorrentLog();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KTORRENTLOG_H