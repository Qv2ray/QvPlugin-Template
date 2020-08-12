#include "SimplePlugin.hpp"

#include <QDateTime>
#include <QLabel>
#include <QMetaEnum>

SimplePlugin plugin;
SimpleKernel kernel;
SimpleSerializer serializer;
SimpleEventHandler eventHandler;
SimpleGUIInterface guiInterface;

bool SimplePlugin::InitializePlugin(const QString &, const QJsonObject &)
{
    emit PluginLog("Initialize plugin.");
    this->settings = settings;
    outboundHandler = std::make_shared<SimpleSerializer>(this);
    eventHandler = std::make_shared<SimpleEventHandler>(this);
    guiInterface = new SimpleGUIInterface();
    return true;
}
