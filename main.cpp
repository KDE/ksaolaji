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

#include <KAboutData>
#include <KApplication>
#include <KCmdLineArgs>
#include <KLocale>

#include <cstdio>

#include "ksaolajiapp.h"

int main( int argc, char** argv )
{
    KAboutData aboutData( "ksaolaji", 0, ki18n( "KSaoLaJi" ), "0.1",
                          ki18n( "SAO LA JI" ),
                          KAboutData::License_GPL_V3, ki18n( "(c) 2011 Ni Hui" ),
                          KLocalizedString(), 0 );
    aboutData.addAuthor( ki18n( "Ni Hui" ), ki18n( "Author" ), "shuizhuyuanluo@126.com" );
    aboutData.setProgramIconName( "applications-accessories" );

    KCmdLineArgs::init( argc, argv, &aboutData );

    KUniqueApplication::addCmdLineOptions();

    if ( !KUniqueApplication::start() ) {
        fprintf( stderr, "ksaolaji is already running!\n" );
        return 0;
    }

    KSaoLaJiApplication app;
    return app.exec();
}
