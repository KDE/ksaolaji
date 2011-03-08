project(ksaolaji)
cmake_minimum_required(VERSION 2.6)
find_package(KDE4 REQUIRED 4.5)
find_package(Nepomuk REQUIRED)

include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${QT_INCLUDES} ${KDE4_INCLUDES})

# add_definitions(-DKDE_DEFAULT_DEBUG_AREA=259694)

set(ksaolaji_cleaners_SRCS
    cleaner_ark.cpp
    cleaner_choqoktimeline.cpp
    cleaner_cookie.cpp
    cleaner_cookiepolicy.cpp
    cleaner_dolphin.cpp
    cleaner_dummy.cpp
    cleaner_favicon.cpp
    cleaner_fcitxrecord.cpp
    cleaner_flashplayer.cpp
    cleaner_gwenview.cpp
    cleaner_kaffeine.cpp
    cleaner_kate.cpp
    cleaner_kdeglobal.cpp
    cleaner_kgamerenderer.cpp
    cleaner_kget.cpp
    cleaner_kgethistory.cpp
    cleaner_khtmlform.cpp
    cleaner_kickoff.cpp
    cleaner_kiohelpcache.cpp
    cleaner_kiohttpcache.cpp
    cleaner_klipper.cpp
    cleaner_kmid.cpp
    cleaner_kolourpaint.cpp
    cleaner_konqhistory.cpp
    cleaner_konqlocbar.cpp
    cleaner_konqueror.cpp
    cleaner_kpixmapcache.cpp
    cleaner_kpresenter.cpp
    cleaner_krita.cpp
    cleaner_kross.cpp
    cleaner_krunner.cpp
    cleaner_kspread.cpp
    cleaner_ktorrent.cpp
    cleaner_ktorrentlog.cpp
    cleaner_ktrash.cpp
    cleaner_kword.cpp
    cleaner_kwrite.cpp
    cleaner_nepomukcache.cpp
    cleaner_okular.cpp
    cleaner_okulardocdata.cpp
    cleaner_plasmawallpaper.cpp
    cleaner_recentdoc.cpp
    cleaner_rekonqhistory.cpp
    cleaner_rekonqsnap.cpp
    cleaner_smplayer.cpp
    cleaner_thumbnail.cpp
    cleaner_vlc.cpp
    cleaner_winetrickscache.cpp
)

set(ksaolaji_SRCS
    ${ksaolaji_cleaners_SRCS}
    cleaner.cpp
    cleaneritem.cpp
    cleanermodel.cpp
    ksaolajiapp.cpp
    main.cpp
    mainwindow.cpp
)

kde4_add_executable(ksaolaji ${ksaolaji_SRCS})

target_link_libraries(ksaolaji ${KDE4_KIO_LIBS} ${NEPOMUK_LIBRARIES} ${KDE4_KROSSCORE_LIBS})

install(TARGETS ksaolaji ${INSTALL_TARGETS_DEFAULT_ARGS})

install(PROGRAMS ksaolaji.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES ksaolajiui.rc DESTINATION ${DATA_INSTALL_DIR}/ksaolaji)

