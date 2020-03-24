#include "SimplePlugin.hpp"

QString SimplePlugin::Name() const
{
    return "Simple Plugin";
}

QString SimplePlugin::Author() const
{
    emit PluginLog("Test log");
    return "Example Author";
}

QString SimplePlugin::InternalName() const
{
    return "sample_plugin";
}

QString SimplePlugin::Description() const
{
    return "Sample plugin description";
}

QStringList SimplePlugin::OutboundTypes() const
{
    emit PluginLog("Getting outbound types.");
    return {};
}

Qv2rayKernelPlugin *SimplePlugin::GetKernelInstance()
{
    emit PluginLog("Getting kernel instance.");
    return nullptr;
}

void SimplePlugin::InitializePlugin(const QJsonObject &)
{
    emit PluginLog("Initialize plugin.");
}

const QIcon SimplePlugin::Icon() const
{
    emit PluginLog("Getting icon.");
    return QIcon(":/qv2ray.png");
}

const QJsonObject SimplePlugin::GetPluginSettngs()
{
    emit PluginLog("Getting plugin settings.");
    return {};
}

QObject *SimplePlugin::GetQObject()
{
    emit PluginLog("Getting qobject.");
    return this;
}

const QMap<QV2RAY_PLUGIN_UI_TYPE, QWidget *> SimplePlugin::GetUIWidgets()
{
    emit PluginLog("Getting UI Widget.");
    return {};
}

void SimplePlugin::PluginHook(QV2RAY_PLUGIN_HOOK_TYPE, QV2RAY_PLUGIN_HOOK_SUBTYPE, QVariant)
{
    emit PluginLog("Processing Plugin Hook.");
}

QV2RAY_PLUGIN_HOOK_TYPE_FLAGS SimplePlugin::PluginHooks() const
{
    emit PluginLog("Getting Plugin Hook.");
    return QV2RAY_PLUGIN_HOOK_TYPE::NONE;
}

QV2RAY_SPECIAL_PLUGIN_TYPE SimplePlugin::SpecialPluginType() const
{
    emit PluginLog("Getting Special Plugin Type.");
    return QV2RAY_SPECIAL_PLUGIN_TYPE::SPECIAL_TYPE_NONE;
}
