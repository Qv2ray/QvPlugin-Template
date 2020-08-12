#pragma once

#include "QvGUIPluginInterface.hpp"
#include "QvPluginInterface.hpp"
#include "core/EventHandler.hpp"
#include "core/Kernel.hpp"
#include "core/Serializer.hpp"

#include <QObject>
#include <QtPlugin>

class QLabel;
using namespace Qv2rayPlugin;

class SimpleGUIInterface : public Qv2rayPluginGUIInterface
{
  public:
    explicit SimpleGUIInterface() : Qv2rayPluginGUIInterface(){};
    ~SimpleGUIInterface(){};
    QIcon Icon() const override
    {
        return QIcon(":/assets/qv2ray.png");
    }
    /// Qv2ray will take the ownership.
    std::unique_ptr<QvPluginSettingsWidget> GetSettingsWidget() const override
    {
        return nullptr;
    }
    /// Qv2ray will NOT take the ownership.
    std::shared_ptr<QvPluginEditor> GetInboundEditor() const override
    {
        return nullptr;
    }
    std::shared_ptr<QvPluginEditor> GetOutboundEditor() const override
    {
        return nullptr;
    }
    std::shared_ptr<QvPluginMainWindowWidget> GetMainWindowWidget() const override
    {
        return nullptr;
    }
};

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
        return { "QvSimplePlugin",                                 //
                 "Qv2ray Workgroup",                               //
                 "qvplugin_test",                                  //
                 "QvSimplePlugin is a simple plugin for testing.", //
                 "v1.0.0",                                         //
                 "https://update.fakeplugin.org/version",          //
                 {
                     COMPONENT_OUTBOUND_HANDLER, //
                     COMPONENT_KERNEL,           //
                     COMPONENT_EVENT_HANDLER,    //
                     // COMPONENT_INBOUND_EDITOR,
                     // COMPONENT_OUTBOUND_EDITOR,
                     // COMPONENT_OUTBOUND_HANDLER,
                     // COMPONENT_MAINWINDOW_WIDGET,
                     // COMPONENT_SUBSCRIPTION_ADAPTER,
                 } };
    }

    bool InitializePlugin(const QString &, const QJsonObject &) override;
    //
    std::shared_ptr<PluginOutboundHandler> GetOutboundHandler() const override
    {
        return outboundHandler;
    }
    std::shared_ptr<PluginEventHandler> GetEventHandler() const override
    {
        return eventHandler;
    }
    std::unique_ptr<PluginKernel> CreateKernel() const override
    {
        return std::make_unique<SimpleKernel>();
    }
    QList<QString> GetKernelProtocols() const override
    {
        return { "fake protocol" };
    }
    Qv2rayPluginGUIInterface *GetGUIInterface() const override
    {
        return guiInterface;
    }
    //
  signals:
    void PluginLog(const QString &) const override;
    void PluginErrorMessageBox(const QString &, const QString &) const override;

  private:
    std::shared_ptr<PluginOutboundHandler> outboundHandler;
    std::shared_ptr<PluginEventHandler> eventHandler;
    SimpleGUIInterface *guiInterface;
};
