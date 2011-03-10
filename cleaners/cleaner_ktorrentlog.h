#ifndef CLEANER_KTORRENTLOG_H
#define CLEANER_KTORRENTLOG_H

#include "cleaner.h"

class CleanerKTorrentLog : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKTorrentLog();
        virtual ~CleanerKTorrentLog();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KTORRENTLOG_H
