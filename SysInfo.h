#ifdef _WIN32
#include "SysInfoWindowsImpl.h"
#elif defined(Q_OS_MAC)
#include "SysInfoMacImpl.h"
#elif defined(__linux__)
//Q_OS_LINUX didn't work https://stackoverflow.com/questions/6649936/c-compiling-on-windows-and-linux-ifdef-switch
#include "SysInfoLinuxImpl.h"
#endif

#ifndef SYSINFO_H
#define SYSINFO_H
#include <QtGlobal>
#include <QVector>

class SysInfo
{
    SysInfo(const SysInfo& ) = delete;
    SysInfo& operator=(const SysInfo& ) = delete;

protected:
    explicit SysInfo();
public:
    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

    virtual ~SysInfo() = default;
    static SysInfo& instance();

};

#endif // SYSINFO_H
