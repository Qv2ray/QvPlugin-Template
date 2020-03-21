#include "SimplePlugin.hpp"

QString SimplePlugin::Name() const
{
    emit PluginLog("Test log - name");
    return "Simple Plugin";
}

QString SimplePlugin::Author() const
{
    emit PluginLog("Test log");
    return "Example Author";
}
