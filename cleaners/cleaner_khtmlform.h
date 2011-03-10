#ifndef CLEANER_KHTMLFORM_H
#define CLEANER_KHTMLFORM_H

#include "cleaner.h"

class CleanerKHTMLForm : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKHTMLForm();
        virtual ~CleanerKHTMLForm();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KHTMLFORM_H
