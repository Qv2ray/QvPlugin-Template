#pragma once

#include "QvGUIPluginInterface.hpp"
#include "ui_PluginMainWindowWidget.h"

class SimplePluginMainWindowWidget
    : public Qv2rayPlugin::QvPluginMainWindowWidget
    , private Ui::PluginMainWindowWidget
{
    Q_OBJECT

  public:
    explicit SimplePluginMainWindowWidget(QWidget *parent = nullptr);
    const QList<QMenu *> GetMenus() override
    {
        return {};
    }

  protected:
    void changeEvent(QEvent *e) override;
};
