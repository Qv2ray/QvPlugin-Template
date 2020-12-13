#pragma once

#include "QvGUIPluginInterface.hpp"
#include "QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

class SimplePlugin
    : public QObject
    , Qv2rayInterface
{
    Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    //
    // Basic metainfo of this plugin
    const QvPluginMetadata GetMetadata() const override
    {
        return { "Qv2ray Demo Plugin",                             //
                 "Qv2ray Workgroup",                               //
                 "qvplugin_test",                                  //
                 "QvSimplePlugin is a simple plugin for testing.", //
                 "v0.8.9",                                         //
                 "Qv2ray/QvPlugin-Template",                       //
                 {
                     COMPONENT_OUTBOUND_HANDLER,     //
                     COMPONENT_KERNEL,               //
                     COMPONENT_EVENT_HANDLER,        //
                     COMPONENT_SUBSCRIPTION_ADAPTER, //
                     COMPONENT_GUI                   //
                 },
                 UPDATE_GITHUB_RELEASE };
    }
    ~SimplePlugin(){};
    bool InitializePlugin(const QString &, const QJsonObject &) override;

  signals:
    void PluginLog(const QString &) const override;
    void PluginErrorMessageBox(const QString &, const QString &) const override;
};
