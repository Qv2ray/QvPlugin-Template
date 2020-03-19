TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../echowindow
HEADERS         = SimplePlugin.hpp interface/QvPluginInterface.hpp
SOURCES         = SimplePlugin.cpp
TARGET          = $$qtLibraryTarget(QvSimplePlugin)
DESTDIR         = ../plugins

CONFIG += install_ok  # Do not cargo-cult this!
