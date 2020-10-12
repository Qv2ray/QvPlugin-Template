#include "SimplePlugin.hpp"

#include "core/EventHandler.hpp"
#include "core/Kernel.hpp"
#include "core/OutboundHandler.hpp"
#include "core/SubscriptionAdapter.hpp"
#include "ui/Interface.hpp"

bool SimplePlugin::InitializePlugin(const QString &, const QJsonObject &_settings)
{
    emit PluginLog("Initialize plugin.");
    this->settings = _settings;
    outboundHandler = std::make_shared<SimpleSerializer>();
    eventHandler = std::make_shared<SimpleEventHandler>();
    kernelInterface = std::make_shared<SimpleKernelInterface>();
    subscriptionAdapter = std::make_shared<SimpleSubsriptionInterface>();
    guiInterface = new SimpleGUIInterface();
    return true;
}
