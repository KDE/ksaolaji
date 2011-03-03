#ifndef CLEANER_KTRASH_H
#define CLEANER_KTRASH_H

#include "cleaner.h"

class CleanerKTrash : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKTrash( QObject* parent = 0 );
        virtual ~CleanerKTrash();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KTRASH_H
