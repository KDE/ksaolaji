#ifndef CLEANER_DUMMY_H
#define CLEANER_DUMMY_H

#include <ksaolaji/cleaner_plugin.h>

class CleanerDummy : public KSaoLaJi::CleanerPlugin
{
    Q_OBJECT
    public:
        explicit CleanerDummy( QObject* parent, const QVariantList& args );
        virtual ~CleanerDummy();
        virtual bool isThreadSafe() const;
        virtual QString uniqueName();
        virtual QString description();
        virtual QString iconName();
        virtual bool youlaji();
        virtual bool saolaji();
};

#endif // CLEANER_DUMMY_H
