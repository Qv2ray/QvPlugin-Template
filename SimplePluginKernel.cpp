#include "SimplePluginKernel.hpp"

SimplePluginKernel::SimplePluginKernel(QObject *parent) : Qv2rayPlugin::QvPluginKernel(parent)
{
}
bool SimplePluginKernel::StartKernel()
{
    return true;
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
