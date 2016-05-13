#include "windows10processormining.h"

#ifdef Q_OS_WIN
#include <windows.h>
#include <intrin.h>

#include <iostream>
#include <string>
#endif

Windows10ProcessorMining::Windows10ProcessorMining()
{
}

QJsonObject Windows10ProcessorMining::getData() {
    QJsonObject json;
    int CPUInfo[4] = {-1};
    char CPUBrandString[0x40];
    __cpuid(CPUInfo, 0x80000000);
    unsigned int nExIds = CPUInfo[0];
    memset(CPUBrandString, 0, sizeof(CPUBrandString));
    for (unsigned int i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        if  (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    json["model"] = CPUBrandString;

    #ifdef Q_PROCESSOR_X86_32
        json["arch"] = "32 Bits";
    #endif
    #ifdef Q_PROCESSOR_X86_64
        json["arch"] = "64 Bits";
    #endif

    SYSTEM_INFO sysinfo;
    GetSystemInfo( &sysinfo );
    int numCPU = sysinfo.dwNumberOfProcessors;
    json["cores"] = QString::number(numCPU);

    json["usage"] = "NaN";

    return json;
}

