#ifndef CLEANERITEM_H
#define CLEANERITEM_H

#include <QString>

namespace KSaoLaJi { class Cleaner; }

class CleanerItem
{
    public:
        explicit CleanerItem( KSaoLaJi::Cleaner* cleaner );
        ~CleanerItem();
        QString description() const;
        QString iconName() const;
        bool youlaji( bool force = false );
        bool saolaji();
        bool isChecked() const;
        void setChecked( bool isChecked );
    private:
        KSaoLaJi::Cleaner* m_cleaner;
        bool m_youlaji;
        bool m_isChecked;
};

#endif // CLEANERITEM_H