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
        const auto items = { "Item1", "Item2", "Item3", "Item4", "Item5" };
        //
        auto restaurants = new QMenu("Restaurants", this);
        auto toilets = new QMenu("Toilets", this);
        auto hotels = new QMenu("Hotels", this);
        //
        for (const auto &item : items)
        {
            restaurants->addAction(item);
            toilets->addAction(item);
            hotels->addAction(item);
        }
        return { restaurants, toilets, hotels };
    }

  protected:
    void changeEvent(QEvent *e) override;
};
