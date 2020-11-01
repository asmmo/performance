#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#ifndef SYSINFO_H
#include <SysInfo.h>
#endif
class SysInfoLinuxImpl : public SysInfo
{
    QVector<qulonglong> cpuLoadLastValues;
    QVector<qulonglong> cpuLoadAverageValues;
    QVector<qulonglong> cpuRawData();
public:
    SysInfoLinuxImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

};
#endif // SYSINFOLINUXIMPL_H
