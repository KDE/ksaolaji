#ifndef CLEANER_PLUGIN_H
#define CLEANER_PLUGIN_H

/** @file cleaner_plugin.h is part of KSaoLaJi and defines plugin base class @class CleanerPlugin. */
#include <QObject>
#include <QVariantList>
#include "ksaolaji_export.h"
#include "cleaner.h"

/** @namespace KSaoLaJi collects classes related to implementing a cleaner. */
namespace KSaoLaJi {

/**
 * @class CleanerPlugin ksaolaji/cleaner_plugin.h
 * @short The base CleanerPlugin class for all cleaner plugins
 * This class works as the glue between cleaner interface and KSaoLaJi plugin loader.
 * Plugins should implement all the interfaces defined in @class Cleaner
 * See @class Cleaner to get more detail on implementing cleaner.
 *
 * @e KSAOLAJI_EXPORT_PLUGIN can be used to register a cleaner.
 * See ksaolaji/examples/cpp for a cleaner plugin example.
 *
 * @author Ni Hui <shuizhuyuanluo@126.com>
 * @date 2011/3/10
 */
class KSAOLAJI_EXPORT CleanerPlugin : public QObject, public Cleaner
{
    Q_OBJECT
    public:
        /**
         * Constructor
         * The default base class routine does nothing.
         * Cleaner plugin can do initializing in class constructor.
         */
        explicit CleanerPlugin( QObject* parent, const QVariantList& args );

        /**
         * Destructor
         * The default base class routine does nothing.
         */
        virtual ~CleanerPlugin();
};

}

#endif // CLEANER_PLUGIN_H
