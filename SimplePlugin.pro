TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
HEADERS         = SimplePlugin.hpp interface/QvPluginInterface.hpp
SOURCES         = SimplePlugin.cpp
TARGET          = $$qtLibraryTarget(QvSimplePlugin)

RESOURCES += \
    resx.qrc
