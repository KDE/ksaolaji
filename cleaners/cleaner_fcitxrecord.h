#ifndef CLEANER_FCITXRECORD_H
#define CLEANER_FCITXRECORD_H

#include "cleaner.h"

class CleanerFcitxRecord : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerFcitxRecord();
        virtual ~CleanerFcitxRecord();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_FCITXRECORD_H
