#include "SimplePlugin.hpp"

#include <QDateTime>
#include <QLabel>

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

Qv2ray::Qv2rayKernelPlugin *SimplePlugin::GetKernelInstance()
{
    emit PluginLog("Getting kernel instance.");
    return nullptr;
}

void SimplePlugin::InitializePlugin(const QJsonObject &)
{
    emit PluginLog("Initialize plugin.");
    pluginWidget = new QLabel;
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

const QWidget *SimplePlugin::GetUIWidgets(Qv2ray::QV2RAY_PLUGIN_UI_TYPE type)
{
    emit PluginLog("Getting UI Widget.");
    switch (type)
    {
        case Qv2ray::UI_TYPE_INBOUND_EDITOR:
        case Qv2ray::UI_TYPE_OUTBOUND_EDITOR:
        case Qv2ray::UI_TYPE_PREFERENCE_WINDOW:
            pluginWidget->setText("Plugin widget opened at: " + QDateTime::currentDateTime().toString());
            return pluginWidget;

        case Qv2ray::UI_TYPE_GROUP_EDITOR: return nullptr;
    }
    return nullptr;
}

void SimplePlugin::PluginHook(Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE, Qv2ray::QV2RAY_PLUGIN_HOOK_SUBTYPE, QVariant)
{
    emit PluginLog("Processing Plugin Hook.");
}

Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE_FLAGS SimplePlugin::PluginHooks() const
{
    emit PluginLog("Getting Plugin Hook.");
    // We want all events!
    return { Qv2ray::HOOK_TYPE_NONE, Qv2ray::HOOK_TYPE_CONFIG_EVENTS, Qv2ray::HOOK_TYPE_CONFIG_STATE_EVENTS, Qv2ray::HOOK_TYPE_STATS_EVENTS };
}

Qv2ray::QV2RAY_SPECIAL_PLUGIN_TYPE SimplePlugin::SpecialPluginType() const
{
    emit PluginLog("Getting Special Plugin Type.");
    return Qv2ray::SPECIAL_TYPE_NONE;
}
