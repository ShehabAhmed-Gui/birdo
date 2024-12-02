cmake_minimum_required(VERSION 3.16)

project(Birdo VERSION 1.0 LANGUAGES CXX)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core Gui Quick QuickControls2 Widgets
    Multimedia MultimediaWidgets)

pkg_check_modules(libusb REQUIRED IMPORTED_TARGET libusb-1.0)
pkg_check_modules(FFMPEG REQUIRED IMPORTED_TARGET libavutil)

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/client/main.cpp
)

set(HEADERS
)

qt_standard_project_setup()

qt6_add_resources(SOURCES "client/core/resources.qrc")

qt_add_executable(Birdo
    ${SOURCES}
    ${HEADERS}
)

set_target_properties(Birdo PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

target_link_libraries(Birdo PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    PkgConfig::libusb
    PkgConfig::FFMPEG
    )

include(GNUInstallDirs)
install(TARGETS Birdo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
