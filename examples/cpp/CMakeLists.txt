project(ksaolaji_cleaner_dummy)
cmake_minimum_required(VERSION 2.6)
find_package(KDE4 REQUIRED 4.5)

include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${QT_INCLUDES} ${KDE4_INCLUDES})

############ ksaolaji dummy cleaner plugin ############

kde4_add_plugin(ksaolaji_cleaner_dummy ksaolaji_cleaner_dummy.cpp)
target_link_libraries(ksaolaji_cleaner_dummy ${KDE4_KDEUI_LIBS} ksaolajicleaner)
install(TARGETS ksaolaji_cleaner_dummy DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES ksaolaji_cleaner_dummy.desktop DESTINATION ${SERVICES_INSTALL_DIR})
