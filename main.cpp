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
