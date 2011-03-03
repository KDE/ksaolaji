#ifndef CLEANER_KGAMERENDERER_H
#define CLEANER_KGAMERENDERER_H

#include "cleaner.h"

class CleanerKGameRenderer : public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerKGameRenderer( QObject* parent = 0 );
        virtual ~CleanerKGameRenderer();
        virtual QString description();
        virtual QString iconName();

        /** you mei you la ji ? */
        virtual bool youlaji();
        /** sao la ji */
        virtual bool saolaji();
};

#endif // CLEANER_KGAMERENDERER_H
