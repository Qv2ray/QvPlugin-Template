#pragma once
#include "QvPluginProcessor.hpp"

class SimpleKernel : public Qv2rayPlugin::PluginKernel
{
  public:
    explicit SimpleKernel(QObject *parent = nullptr);
    /// Kernel related operations
    void SetConnectionSettings(const QMap<Qv2rayPlugin::KernelOptionFlags, QVariant> &settings, const QJsonObject &connectionInfo) override;
    bool StartKernel() override;
    bool StopKernel() override;
};
