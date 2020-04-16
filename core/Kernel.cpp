#include "Kernel.hpp"

SimplePluginKernel::SimplePluginKernel(QObject *parent) : Qv2rayPlugin::QvPluginKernel(parent)
{
}
bool SimplePluginKernel::StartKernel()
{
    return true;
}
void SimplePluginKernel::SetConnectionSettings(const QString &listenAddress, const QMap<QString, int> &inbound, const QJsonObject &settings)
{
    Q_UNUSED(inbound)
    Q_UNUSED(settings)
    Q_UNUSED(listenAddress)
}
bool SimplePluginKernel::StopKernel()
{
    emit OnKernelCrashed("Yay!");
    return true;
}
const QList<Qv2rayPlugin::QvPluginOutboundProtocolObject> SimplePluginKernel::KernelOutboundCapabilities() const
{
    return { { "Fake outbound", "pseudo" } };
}
