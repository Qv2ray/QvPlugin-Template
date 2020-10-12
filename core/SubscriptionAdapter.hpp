#pragma once
#include "QvPluginInterface.hpp"

class SimpleSubscriptionDecoder : public Qv2rayPlugin::SubscriptionDecoder
{
  public:
    explicit SimpleSubscriptionDecoder() : Qv2rayPlugin::SubscriptionDecoder()
    {
    }
    ~SimpleSubscriptionDecoder(){};
};

class SimpleSubsriptionInterface : public Qv2rayPlugin::SubscriptionInterface
{
    QList<Qv2rayPlugin::ProtocolInfoObject> SupportedSubscriptionTypes() const
    {
        return {};
    }
    std::shared_ptr<Qv2rayPlugin::SubscriptionDecoder> GetSubscriptionDecoder(const QString &type) const
    {
        return {};
    }
};
