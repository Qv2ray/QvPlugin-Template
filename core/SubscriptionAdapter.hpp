#pragma once
#include "QvPluginInterface.hpp"
class SimpleSubscriptionAdapter : public Qv2rayPlugin::PluginSubscriptionAdapter
{
  public:
    explicit SimpleSubscriptionAdapter() : Qv2rayPlugin::PluginSubscriptionAdapter()
    {
    }
    ~SimpleSubscriptionAdapter(){};
};
