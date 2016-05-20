#include "windows7processormining.h"

#ifdef Q_OS_WIN
    #include <windows.h>
    #include <intrin.h>
    #include <unistd.h>
    #include <TCHAR.h>
    #include <pdh.h>
    #include <pdhmsg.h>
#endif

Windows7ProcessorMining::Windows7ProcessorMining()
{
}

QJsonObject Windows7ProcessorMining::getData() {
    QJsonObject json;


#ifdef Q_OS_WIN
    //Partie modèle du processeur
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

    //Partie archittecture du processeur
    #ifdef Q_PROCESSOR_X86_32
        json["arch"] = "32 Bits";
    #endif
    #ifdef Q_PROCESSOR_X86_64
        json["arch"] = "64 Bits";
    #endif

    //Partie nombre de coeurs du processeur
    SYSTEM_INFO sysinfo;
    GetSystemInfo( &sysinfo );
    int numCPU = sysinfo.dwNumberOfProcessors;
    json["cores"] = QString::number(numCPU);

    //Partie usage du processeur
    static PDH_HQUERY cpuQuery;
    static PDH_HCOUNTER cpuTotal;
    PDH_FMT_COUNTERVALUE counterVal;

    PdhOpenQuery((LPCWSTR)NULL, (DWORD)NULL, &cpuQuery);
    const LANGID langId = GetUserDefaultUILanguage();
    //Français (dans l'ordre BE, CA, FR, LU, MC, CH)
    if (langId == 2060 || langId == 3084 || langId == 1036 || langId == 5132 || langId == 6156 || langId == 4108) {
        PdhAddCounter(cpuQuery, L"\\Processeur(_total)\\% temps processeur", (DWORD)NULL, &cpuTotal);
    }
    else {
        PdhAddCounter(cpuQuery, L"\\Processor(_total)\\% processor time", (DWORD)NULL, &cpuTotal);
    }
    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    while (counterVal.doubleValue == 0) {
        usleep(1000);
        PdhCollectQueryData(cpuQuery);
        PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    }
    int counter = counterVal.doubleValue;
    json["usage"] = QString::number(counter);
 #endif

    return json;
}

