#include "QvGUIPluginInterface.hpp"
#include "ui/PluginInboundEditor.hpp"
#include "ui/PluginMainWindowWidget.hpp"
#include "ui/PluginOutboundEditor.hpp"
#include "ui/PluginSettingsWidget.hpp"

using namespace Qv2rayPlugin;

class SimpleGUIInterface : public PluginGUIInterface
{
  public:
    explicit SimpleGUIInterface()
    {
        AddEditor(inbound, "fake-protocol-in", "Fake Protocol Inbound", SimplePluginInboundEditor);
        AddEditor(outbound, "fake-protocol-out", "Fake Protocol Outbound", SimplePluginOutboundEditor);
        this->settingsWidget = std::make_unique<SimplePluginSettingsWidget>();
        this->mainWindowWidget = std::make_unique<SimplePluginMainWindowWidget>();
    }
    QList<PluginGuiComponentType> GetComponents() const override
    {
        return { GUI_COMPONENT_SETTINGS, GUI_COMPONENT_INBOUND_EDITOR, GUI_COMPONENT_OUTBOUND_EDITOR, GUI_COMPONENT_MAINWINDOW_WIDGET };
    }
    ~SimpleGUIInterface(){};
    QIcon Icon() const override
    {
        return QIcon(":/assets/qv2ray.png");
    }
};
