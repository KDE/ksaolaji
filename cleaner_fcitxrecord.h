#ifndef CLEANER_FCITXRECORD_H
#define CLEANER_FCITXRECORD_H

#include "cleaner.h"

class CleanerFcitxRecord : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerFcitxRecord();
        virtual ~CleanerFcitxRecord();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_FCITXRECORD_H
