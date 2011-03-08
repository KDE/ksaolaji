#ifndef CLEANER_KROSS_H
#define CLEANER_KROSS_H

#include "cleaner.h"
namespace Kross { class Action; }

class CleanerKross : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKross( QString file, QObject* parent = 0 );
        virtual ~CleanerKross();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
    private:
        Kross::Action* m_action;
        QString m_description;
        QString m_iconName;
};

#endif // CLEANER_KROSS_H
