#pragma once

#include "interface/QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

class SimplePlugin
    : public QObject
    , Qv2rayInterface
{
    Q_INTERFACES(Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    QV2RAY_PLUGIN_HOOK_TYPE_FLAGS PluginHooks() const override
    {
        return QV2RAY_PLUGIN_HOOK_TYPE::NONE;
    };
    QV2RAY_SPECIAL_PLUGIN_TYPE SpecialPluginType() const override
    {
        return QV2RAY_SPECIAL_PLUGIN_TYPE::SPECIAL_TYPE_NONE;
    }
    //
    // Basic metainfo of this plugin
    QString Name() const override;
    QString InternalName() const override
    {
        return "sample_plugin";
    }
    QString Author() const override;
    QString Description() const override
    {
        return "Sample plugin description";
    }
    //
    QStringList OutboundTypes() const override
    {
        return {};
    }
    //
    const QMap<QV2RAY_PLUGIN_UI_TYPE, QWidget *> GetUIWidgets() override
    {
        return {};
    }
    QObject *GetKernelInstance() override
    {
        return nullptr;
    }
    //
    void InitializePlugin(const QJsonObject &) override
    {
    }
    const QJsonObject GetPluginSettngs() override
    {
        return {};
    }
    //
    /// The hook function, for SPECIAL_TYPE_NONE
    void PluginHook(QV2RAY_PLUGIN_HOOK_TYPE, QV2RAY_PLUGIN_HOOK_SUBTYPE, QVariant) override
    {
    }
  signals:
    void PluginLog(const QString &) const override;
};
