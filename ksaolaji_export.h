#ifndef KSAOLAJI_EXPORT_H
#define KSAOLAJI_EXPORT_H

#include <kdemacros.h>
#include <KPluginFactory>
#include <KPluginLoader>

#ifdef MAKE_KSAOLAJI_LIB
// we are building this library
#define KSAOLAJI_EXPORT KDE_EXPORT
#else
// we are using this library
#define KSAOLAJI_EXPORT KDE_IMPORT
#endif

#define KSAOLAJI_EXPORT_PLUGIN( classname ) \
    K_PLUGIN_FACTORY( KSaoLaJiFactory, registerPlugin< classname >(); ) \
    K_EXPORT_PLUGIN( KSaoLaJiFactory( "classname" ) )

#endif // KSAOLAJI_EXPORT_H
