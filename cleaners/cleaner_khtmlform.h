#ifndef CLEANER_KHTMLFORM_H
#define CLEANER_KHTMLFORM_H

#include "cleaner.h"

class CleanerKHTMLForm : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKHTMLForm();
        virtual ~CleanerKHTMLForm();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KHTMLFORM_H
