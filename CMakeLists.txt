cmake_minimum_required(VERSION 3.16)

project(samegame VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(SAMEGAME_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/samegamewidget.cpp
    src/samegamewidget.h
    src/samegame.qrc
)

add_executable(samegame ${SAMEGAME_SOURCES})

target_link_libraries(samegame PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

if(WIN32)
    target_sources(samegame PRIVATE src/samegame_win.rc)
endif()

# Install layout mirrors the old samegame.pro unix rules.
include(GNUInstallDirs)
install(TARGETS samegame RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES src/samegame.desktop DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications)
install(FILES src/gpl.txt src/readme.txt DESTINATION ${CMAKE_INSTALL_DOCDIR})
install(FILES src/samegame.svg DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/scalable/apps)
