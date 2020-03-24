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
    QV2RAY_PLUGIN_HOOK_TYPE_FLAGS PluginHooks() const override;
    QV2RAY_SPECIAL_PLUGIN_TYPE SpecialPluginType() const override;
    //
    // Basic metainfo of this plugin
    QString Name() const override;
    QString InternalName() const override;
    QString Author() const override;
    QString Description() const override;
    //
    QStringList OutboundTypes() const override;
    //
    const QMap<QV2RAY_PLUGIN_UI_TYPE, QWidget *> GetUIWidgets() override;
    QObject *GetQObject() override;
    Qv2rayKernelPlugin *GetKernelInstance() override;
    //
    void InitializePlugin(const QJsonObject &) override;
    const QIcon Icon() const override;
    const QJsonObject GetPluginSettngs() override;
    //
    /// The hook function, for SPECIAL_TYPE_NONE
    void PluginHook(QV2RAY_PLUGIN_HOOK_TYPE, QV2RAY_PLUGIN_HOOK_SUBTYPE, QVariant) override;
  signals:
    void PluginLog(const QString &) const override;
};
