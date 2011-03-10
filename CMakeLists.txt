project(ksaolaji)
cmake_minimum_required(VERSION 2.6)
find_package(KDE4 REQUIRED 4.5)
find_package(Nepomuk REQUIRED)

include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${QT_INCLUDES} ${KDE4_INCLUDES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# add_definitions(-DKDE_DEFAULT_DEBUG_AREA=259694)

############## ksaolaji cleaner library ###############

kde4_add_library(ksaolajicleaner SHARED cleaner_plugin.cpp)
target_link_libraries(ksaolajicleaner ${QT_QTCORE_LIBRARY})
set_target_properties(ksaolajicleaner PROPERTIES VERSION 0.0.1 SOVERSION 0)
install(TARGETS ksaolajicleaner ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES ksaolajicleaner.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR})
install(FILES
    ksaolaji_export.h
    cleaner.h
    cleaner_plugin.h
    DESTINATION ${INCLUDE_INSTALL_DIR}/ksaolaji
    COMPONENT Devel
)

###################### ksaolaji ######################

file(GLOB ksaolaji_cleaners_SRCS "cleaners/*.cpp")

set(ksaolaji_SRCS
    ${ksaolaji_cleaners_SRCS}
    cleaner_kross.cpp
    cleaneritem.cpp
    cleanermodel.cpp
    ksaolajiapp.cpp
    main.cpp
    mainwindow.cpp
)

kde4_add_executable(ksaolaji ${ksaolaji_SRCS})

target_link_libraries(ksaolaji
    ${KDE4_KIO_LIBS}
    ${NEPOMUK_LIBRARIES}
    ${KDE4_KROSSCORE_LIBS}
    ksaolajicleaner
)

install(TARGETS ksaolaji ${INSTALL_TARGETS_DEFAULT_ARGS})

install(PROGRAMS ksaolaji.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES ksaolajiui.rc DESTINATION ${DATA_INSTALL_DIR}/ksaolaji)
