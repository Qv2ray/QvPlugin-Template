#include "SimplePluginEventHandler.hpp"

using namespace Qv2rayPlugin;
SimplePluginEventHandler::SimplePluginEventHandler(QObject *parent) : Qv2rayPlugin::QvPluginEventHandler(parent)
{
}

QvPlugin_EventHandler(SimplePluginEventHandler, Connectivity)
{
    Q_UNUSED(pluginEvent);
}
QvPlugin_EventHandler(SimplePluginEventHandler, SystemProxy)
{
    Q_UNUSED(pluginEvent);
}
QvPlugin_EventHandler(SimplePluginEventHandler, ConnectionEntry)
{
    Q_UNUSED(pluginEvent);
}
QvPlugin_EventHandler(SimplePluginEventHandler, ConnectionStats)
{
    Q_UNUSED(pluginEvent);
}
