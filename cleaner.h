#ifndef CLEANER_H
#define CLEANER_H

#include <QString>

namespace KSaoLaJi {

class Cleaner
{
    public:
        explicit Cleaner() {}
        virtual ~Cleaner() {}
        virtual QString uniqueName() = 0;
        virtual QString description() = 0;
        virtual QString iconName() = 0;

        /** you mei you la ji ? */
        virtual bool youlaji() = 0;
        /** sao la ji */
        virtual bool saolaji() = 0;
};

}

#endif // CLEANER_H
