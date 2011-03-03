#ifndef CLEANER_GWENVIEW_H
#define CLEANER_GWENVIEW_H

#include "cleaner.h"

class CleanerGwenview : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerGwenview( QObject* parent = 0 );
        virtual ~CleanerGwenview();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_GWENVIEW_H
