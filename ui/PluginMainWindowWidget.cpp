#include "PluginMainWindowWidget.hpp"

SimplePluginMainWindowWidget::SimplePluginMainWindowWidget(QWidget *parent) : Qv2rayPlugin::QvPluginMainWindowWidget(parent)
{
    setupUi(this);
}

void SimplePluginMainWindowWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange: retranslateUi(this); break;
        default: break;
    }
}
