#ifndef CLEANER_KPRESENTER_H
#define CLEANER_KPRESENTER_H

#include "cleaner.h"

class CleanerKPresenter : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKPresenter( QObject* parent = 0 );
        virtual ~CleanerKPresenter();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KPRESENTER_H
