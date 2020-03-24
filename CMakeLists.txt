project(QvSimplePlugin)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON )
set(CMAKE_AUTOMOC ON )

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(QvSimplePlugin_HDRS
    SimplePlugin.hpp
    interface/QvPluginInterface.hpp
    )

set(QvSimplePlugin_SRCS
    SimplePlugin.cpp
)

set(QvSimplePlugin_RSCS
    resx.qrc
    )

QT5_ADD_RESOURCES(RSCS ${QvSimplePlugin_RSCS})

set ( QvSimplePlugin_MOCS
	SimplePlugin.hpp
	interface/QvPluginInterface.hpp
	)
QT5_WRAP_CPP(MOCS ${QvSimplePlugin_MOCS})

add_library(QvSimplePlugin MODULE ${QvSimplePlugin_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS})
target_link_libraries(QvSimplePlugin  Qt5::Core Qt5::Gui Qt5::Widgets)
