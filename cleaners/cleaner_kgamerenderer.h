#ifndef CLEANER_KGAMERENDERER_H
#define CLEANER_KGAMERENDERER_H

#include "cleaner.h"

class CleanerKGameRenderer : public KSaoLaJi::Cleaner
{
    public:
        explicit CleanerKGameRenderer();
        virtual ~CleanerKGameRenderer();
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_KGAMERENDERER_H
