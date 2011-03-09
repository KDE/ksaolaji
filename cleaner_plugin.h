#ifndef CLEANER_PLUGIN_H
#define CLEANER_PLUGIN_H

#include <QObject>
#include <QVariantList>
#include "ksaolaji_export.h"
#include "cleaner.h"

namespace KSaoLaJi {

class KSAOLAJI_EXPORT CleanerPlugin : public QObject, public Cleaner
{
    Q_OBJECT
    public:
        explicit CleanerPlugin( QObject* parent, const QVariantList& args );
        virtual ~CleanerPlugin();
};

}

#endif // CLEANER_PLUGIN_H
