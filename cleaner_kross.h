#ifndef CLEANER_KROSS_H
#define CLEANER_KROSS_H

#include "cleaner.h"
namespace Kross { class Action; }

class CleanerKross : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKross( const QString& file );
        virtual ~CleanerKross();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
    private:
        Kross::Action* m_action;
        QString m_uniqueName;
        QString m_description;
        QString m_iconName;
};

#endif // CLEANER_KROSS_H
