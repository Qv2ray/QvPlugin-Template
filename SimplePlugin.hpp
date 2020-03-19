#pragma once

#include "interface/QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

class SimplePlugin
    : public QObject
    , Qv2rayInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_INTERFACES(Qv2rayInterface)

  public:
    QString Name() override;
    QString Author() override;
};
