#include "SimplePlugin.hpp"

#include "core/EventHandler.hpp"
#include "core/Kernel.hpp"
#include "core/OutboundHandler.hpp"
#include "core/SubscriptionAdapter.hpp"
#include "ui/Interface.hpp"

bool SimplePlugin::InitializePlugin(const QString &, const QJsonObject &)
{
    emit PluginLog("Initialize plugin.");
    this->settings = settings;
    outboundHandler = std::make_shared<SimpleSerializer>();
    eventHandler = std::make_shared<SimpleEventHandler>();
    kernelInterface = std::make_shared<SimpleKernelInterface>();
    subscriptionAdapter = std::make_shared<SimpleSubscriptionAdapter>();
    guiInterface = new SimpleGUIInterface();
    return true;
}
