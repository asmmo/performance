#include "SysInfoLinuxImpl.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <QTextStream>
#include <QFile>

SysInfoLinuxImpl::SysInfoLinuxImpl() :SysInfo{}, cpuLoadLastValues{cpuRawData()}{}
double SysInfoLinuxImpl::memoryUsed()
{
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    qulonglong totalMemory = (memInfo.totalram + memInfo.totalswap) * memInfo.mem_unit;

    qulonglong totalMemoryUsed = memInfo.totalram - memInfo.freeram;
    totalMemoryUsed += memInfo.totalswap - memInfo.freeswap;
    totalMemoryUsed *= memInfo.mem_unit;
    double percent = (double)totalMemoryUsed / (double)totalMemory * 100.0;
    return qBound(0.0, percent, 100.0);
}


QVector<qulonglong> SysInfoLinuxImpl::cpuRawData()
{
    qulonglong totalUser = 0, totalUserNice = 0, totalSystem = 0, totalIdle = 0;

//    QFile file("/proc/st");
    QTextStream stream("/proc/st", QIODevice::ReadOnly);
    //file.open(QIODevice::ReadOnly);
    //QByteArray line = file.readLine();
    stream >> totalUser >> totalUserNice >> totalSystem >> totalIdle;
    //file.close();

/*    std::sscanf(line.data(), "cpu %llu %llu %llu %llu",
    &totalUser, &totalUserNice, &totalSystem,
    &totalIdle);*/


    return {totalUser, totalUserNice, totalSystem, totalIdle};
}


double SysInfoLinuxImpl::cpuLoadAverage()
{
    QVector<qulonglong> firstSample = cpuLoadLastValues;
    cpuLoadLastValues = cpuRawData();
    double overall = (cpuLoadLastValues[0] - firstSample[0])
                     + (cpuLoadLastValues[1] - firstSample[1])
                     + (cpuLoadLastValues[2] - firstSample[2]);
    double total = overall + (cpuLoadLastValues[3] - firstSample[3]);
    double percent = (overall / total) * 100.0;
    return qBound(0.0, percent, 100.0);
}

void SysInfoLinuxImpl::init(){}
