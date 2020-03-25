#pragma once

#include "interface/QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

class QLabel;

class SimplePlugin
    : public QObject
    , Qv2ray::Qv2rayInterface
{
    Q_INTERFACES(Qv2ray::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE_FLAGS PluginHooks() const override;
    Qv2ray::QV2RAY_SPECIAL_PLUGIN_TYPE_FLAGS SpecialPluginType() const override;
    //
    // Basic metainfo of this plugin
    QString Name() const override;
    QString InternalName() const override;
    QString Author() const override;
    QString Description() const override;
    //
    QStringList OutboundTypes() const override;
    //
    QWidget *GetSettingsWidget() override;
    Qv2ray::Qv2rayPluginEditorWidget *GetEditorWidget(Qv2ray::QV2RAY_PLUGIN_UI_TYPE) override;
    QObject *GetQObject() override;
    Qv2ray::Qv2rayKernelPluginObject *GetKernelInstance() override;
    //
    bool UpdatePluginSettings(const QJsonObject &) override;
    bool InitializePlugin(const QJsonObject &) override;
    const QIcon Icon() const override;
    const QJsonObject GetPluginSettngs() override;
    //
    /// The hook function, for SPECIAL_TYPE_NONE
    void ProcessHook(Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE, Qv2ray::QV2RAY_PLUGIN_HOOK_SUBTYPE, QVariant *) override;
  signals:
    void PluginLog(const QString &) const override;

  private:
    QJsonObject settings;
    QLabel *pluginWidget;
};
