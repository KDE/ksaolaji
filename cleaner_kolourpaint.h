#ifndef CLEANER_KOLOURPAINT_H
#define CLEANER_KOLOURPAINT_H

#include "cleaner.h"

class CleanerKolourPaint : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKolourPaint( QObject* parent = 0 );
        virtual ~CleanerKolourPaint();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KOLOURPAINT_H
