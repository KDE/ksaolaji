#ifndef CLEANER_KHTMLFORM_H
#define CLEANER_KHTMLFORM_H

#include "cleaner.h"

class CleanerKHTMLForm : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKHTMLForm( QObject* parent = 0 );
        virtual ~CleanerKHTMLForm();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KHTMLFORM_H
