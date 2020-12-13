#pragma once
#include "QvPluginProcessor.hpp"

class SimpleKernel : public Qv2rayPlugin::PluginKernel
{
  public:
    explicit SimpleKernel();
    /// Kernel related operations
    void SetConnectionSettings(const QMap<Qv2rayPlugin::KernelOptionFlags, QVariant> &settings, const QJsonObject &connectionInfo) override;
    bool StartKernel() override;
    bool StopKernel() override;
    QString GetKernelName() const override;
};

class SimpleKernelInterface : public Qv2rayPlugin::PluginKernelInterface
{
    std::unique_ptr<Qv2rayPlugin::PluginKernel> CreateKernel() const override
    {
        return std::make_unique<SimpleKernel>();
    }
    QList<QString> GetKernelProtocols() const override
    {
        return { "fake-protocol" };
    }
};
