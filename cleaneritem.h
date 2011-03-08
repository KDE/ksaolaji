#ifndef CLEANERITEM_H
#define CLEANERITEM_H

#include <QString>

class Cleaner;

class CleanerItem
{
    public:
        explicit CleanerItem( Cleaner* cleaner );
        ~CleanerItem();
        QString description() const;
        QString iconName() const;
        bool youlaji( bool force = false );
        bool saolaji();
        bool isChecked() const;
        void setChecked( bool isChecked );
    private:
        Cleaner* m_cleaner;
        bool m_youlaji;
        bool m_isChecked;
};

#endif // CLEANERITEM_H
