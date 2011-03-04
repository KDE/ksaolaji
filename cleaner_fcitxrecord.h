#ifndef CLEANER_FCITXRECORD_H
#define CLEANER_FCITXRECORD_H

#include "cleaner.h"

class CleanerFcitxRecord : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerFcitxRecord( QObject* parent = 0 );
        virtual ~CleanerFcitxRecord();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_FCITXRECORD_H
