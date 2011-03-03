#ifndef CLEANER_RECENTDOC_H
#define CLEANER_RECENTDOC_H

#include "cleaner.h"

class CleanerRecentDoc : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerRecentDoc( QObject* parent = 0 );
        virtual ~CleanerRecentDoc();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_RECENTDOC_H
