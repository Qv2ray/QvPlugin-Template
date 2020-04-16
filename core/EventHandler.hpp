#pragma once
#include "QvPluginProcessor.hpp"

class SimplePluginEventHandler : public Qv2rayPlugin::QvPluginEventHandler
{
  public:
    SimplePluginEventHandler(QObject *parent = nullptr);
    QvPlugin_EventHandler_Decl(SystemProxy);
    QvPlugin_EventHandler_Decl(Connectivity);
    QvPlugin_EventHandler_Decl(ConnectionStats);
    QvPlugin_EventHandler_Decl(ConnectionEntry);
};
