#ifndef CLEANER_KTORRENT_H
#define CLEANER_KTORRENT_H

#include "cleaner.h"

class CleanerKTorrent : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKTorrent( QObject* parent = 0 );
        virtual ~CleanerKTorrent();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KTORRENT_H
