cmake_minimum_required(VERSION 3.25)
project(Birdo VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_PREFIX_PATH "G:/Qt/6.5.0/mingw_64/lib/cmake/Qt6/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt_PACKAGES
    Core Gui Multimedia
    LinguistTools MultimediaWidgets
)

set(LIBS
    Qt6::Core Qt6::Gui
    Qt6::Multimedia Qt6::MultimediaWidgets
)

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/client/main.cpp

    ${CMAKE_CURRENT_LIST_DIR}/client/core
    ${CMAKE_CURRENT_LIST_DIR}/client/core/settings
    ${CMAKE_CURRENT_LIST_DIR}/client/core/adjustapp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/client/core/player.cpp
    ${CMAKE_CURRENT_LIST_DIR}/client/core/videocontrols.cpp
    ${CMAKE_CURRENT_LIST_DIR}/client/core/videowidget.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/client/core/adjustapp.h
    ${CMAKE_CURRENT_LIST_DIR}/client/core/player.h
    ${CMAKE_CURRENT_LIST_DIR}/client/core/videocontrols.h
    ${CMAKE_CURRENT_LIST_DIR}/client/core/videowidget.h

)

set(QRC
        ${CMAKE_CURRENT_LIST_DIR}/client/core/birdo.qrc
)

set(UI
    ${CMAKE_CURRENT_LIST_DIR}/client/core/ui/player.ui
)

set(HEADERS ${HEADERS}
    ${CMAKE_CURRENT_LIST_DIR}/client/core/defs.h
)


add_executable(Birdo ${HEADERS} ${SOURCES} ${UI} ${QRC}

)
find_package(Qt6 REQUIRED COMPONENTS
    ${Qt_PACKAGES}
)

target_link_libraries(Birdo PRIVATE
    ${LIBS}
)

qt6_add_resources(${QRC})

set_target_properties(Birdo PROPERTIES
    AUTORCC ON
    AUTOMOC ON
    AUTOUIC ON
)


include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_LIST_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
include(CPack)
