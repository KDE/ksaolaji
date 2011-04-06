/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
