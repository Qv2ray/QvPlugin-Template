#include "SimplePlugin.hpp"

#include <QDateTime>
#include <QLabel>
#include <QMetaEnum>

// Helper template function to convert an enum to QString.
template<typename T>
QString EnumToString(const T &t)
{
    return QMetaEnum::fromType<T>().key(t);
}

QString SimplePlugin::Name() const
{
    return "Simple Plugin";
}

QString SimplePlugin::Author() const
{
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

Qv2ray::Qv2rayKernelPluginObject *SimplePlugin::GetKernelInstance()
{
    emit PluginLog("Getting kernel instance.");
    return nullptr;
}

bool SimplePlugin::UpdatePluginSettings(const QJsonObject &conf)
{
    settings = conf;
    return true;
}

bool SimplePlugin::InitializePlugin(const QJsonObject &settings)
{
    emit PluginLog("Initialize plugin.");
    this->settings = settings;
    pluginWidget = new QLabel;
    return true;
}

const QIcon SimplePlugin::Icon() const
{
    emit PluginLog("Getting icon.");
    return QIcon(":/qv2ray.png");
}

const QJsonObject SimplePlugin::GetPluginSettngs()
{
    emit PluginLog("Getting plugin settings.");
    return settings;
}

QObject *SimplePlugin::GetQObject()
{
    emit PluginLog("Getting qobject.");
    return this;
}

QWidget *SimplePlugin::GetSettingsWidget()
{
    pluginWidget->setText("From Settings: " + settings["msg"].toString());
    return pluginWidget;
}

Qv2ray::Qv2rayPluginEditorWidget *SimplePlugin::GetEditorWidget(Qv2ray::QV2RAY_PLUGIN_UI_TYPE type)
{
    emit PluginLog("Getting UI Widget.");
    switch (type)
    {
        case Qv2ray::UI_TYPE_INBOUND_EDITOR:
        case Qv2ray::UI_TYPE_OUTBOUND_EDITOR:
        case Qv2ray::UI_TYPE_GROUP_EDITOR: break;
    }
    return nullptr;
}

void SimplePlugin::ProcessHook(Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE event, Qv2ray::QV2RAY_PLUGIN_HOOK_SUBTYPE subtype, QVariant *data)
{
    emit PluginLog("Processing Plugin Hook.");
    emit PluginLog("Data: " + EnumToString(event) + ", subtype: " + EnumToString(subtype));
}

Qv2ray::QV2RAY_PLUGIN_HOOK_TYPE_FLAGS SimplePlugin::PluginHooks() const
{
    emit PluginLog("Getting Plugin Hook.");
    // We want all events!
    return { Qv2ray::HOOK_TYPE_NONE,          //
             Qv2ray::HOOK_TYPE_CONFIG_EVENTS, //
             Qv2ray::HOOK_TYPE_STATE_EVENTS,  //
             Qv2ray::HOOK_TYPE_STATS_EVENTS };
}

Qv2ray::QV2RAY_SPECIAL_PLUGIN_TYPE_FLAGS SimplePlugin::SpecialPluginType() const
{
    emit PluginLog("Getting Special Plugin Type.");
    return { Qv2ray::SPECIAL_TYPE_NONE };
}
