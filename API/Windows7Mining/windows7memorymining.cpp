#include "windows7memorymining.h"

#ifdef Q_OS_WIN
    #include "windows.h"
#endif

Windows7MemoryMining::Windows7MemoryMining()
{
}

QJsonObject Windows7MemoryMining::getData() {
    QJsonObject json;

#ifdef Q_OS_WIN
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memory_status)) {
        json["total"] = QString::number(memory_status.ullTotalPhys/(1024*1024))+" Mo";
        json["usage"] = QString::number((memory_status.ullTotalPhys-memory_status.ullAvailPhys)/(1024*1024))+" Mo";
    } else {
      json["error"] = "Memory data mining error";
    }
#endif
    return json;
}
