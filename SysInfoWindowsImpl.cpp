#include "SysInfoWindowsImpl.h"
#include <windows.h>

SysInfoWindowsImpl::SysInfoWindowsImpl():SysInfo{}, cpuLoadLastValues{cpuRawData()}{}

double SysInfoWindowsImpl::memoryUsed()
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memoryStatus);
    qulonglong memoryPhysicalUsed =
        memoryStatus.ullTotalPhys - memoryStatus.ullAvailPhys;
    return (double)memoryPhysicalUsed /
           (double)memoryStatus.ullTotalPhys * 100.0;

}


QVector<qulonglong> SysInfoWindowsImpl::cpuRawData(){

    _FILETIME idleTime;
    _FILETIME kernelTime;
    _FILETIME userTime;
    GetSystemTimes(&idleTime, &kernelTime, &userTime);

    return {convertFileTime(idleTime), convertFileTime(kernelTime), convertFileTime(userTime)};
}


qulonglong SysInfoWindowsImpl::convertFileTime(const _FILETIME& fTime) const{

    ULARGE_INTEGER toBeReturned;
    toBeReturned.HighPart = fTime.dwHighDateTime;
    toBeReturned.LowPart = fTime.dwLowDateTime;
    return toBeReturned.QuadPart;
}


double SysInfoWindowsImpl::cpuLoadAverage()
{
    QVector<qulonglong> firstSample = cpuLoadLastValues;
    cpuLoadLastValues = cpuRawData();

    qulonglong currentIdle = cpuLoadLastValues[0] - firstSample[0];
    qulonglong currentKernel = cpuLoadLastValues[1] - firstSample[1];
    qulonglong currentUser = cpuLoadLastValues[2] - firstSample[2];

    qulonglong currentSystem = currentKernel + currentUser;
    double percent = (currentSystem - currentIdle) * 100.0 /
    currentSystem ;
    return qBound(0.0, percent, 100.0);
}



void SysInfoWindowsImpl::init(){

}
