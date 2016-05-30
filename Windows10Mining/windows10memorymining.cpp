#include "windows10memorymining.h"

#ifdef Q_OS_WIN
    #include "windows.h"
#endif

Windows10MemoryMining::Windows10MemoryMining()
{
}

QJsonObject Windows10MemoryMining::getData() {
    QJsonObject json;

#ifdef Q_OS_WIN
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memory_status)) {
        json["totalMemory"] = QString::number(memory_status.ullTotalPhys/(1024*1024))+" Mo";
        json["usedMemory"] = QString::number((memory_status.ullTotalPhys-memory_status.ullAvailPhys)/(1024*1024))+" Mo";
    } else {
      json["err"] = "Memory mining error";
    }
#endif
    return json;
}
