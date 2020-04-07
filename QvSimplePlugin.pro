QT += core gui widgets
CONFIG += qt c++11 plugin

TEMPLATE = lib

include(interface/QvPluginInterface.pri)

SOURCES += SimplePlugin.cpp
HEADERS += SimplePlugin.hpp
RESOURCES += resx.qrc
