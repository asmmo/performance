#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H
#include <SysInfo.h>
struct _FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const _FILETIME&) const;
    QVector<qulonglong> cpuLoadLastValues;

public:
    SysInfoWindowsImpl();

    void init()override;
    double cpuLoadAverage()override;
    double memoryUsed()override;

};

#endif // SYSINFOWINDOWSIMPL_H
