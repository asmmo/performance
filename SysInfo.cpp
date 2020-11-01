#include "SysInfo.h"

SysInfo::SysInfo()
{

}


SysInfo& SysInfo::instance()
{
    #ifdef Q_OS_WIN
        static SysInfoWindowsImpl singleton;
    #elif defined(Q_OS_MAC)
        static SysInfoMacImpl singleton;
    #elif defined(Q_OS_LINUX)
        static SysInfoLinuxImpl singleton;
    #endif
    return singleton;
}
