#include "windows7osmining.h"

Windows7OSMining::Windows7OSMining()
{
}

QJsonObject Windows7OSMining::getData() {
    QJsonObject json;
    json["os"] = "Windows";
    json["version"] = "7";
    #ifdef Q_OS_WIN32
    json["arch"] = "32 Bits";
    #endif
    #ifdef Q_OS_WIN64
    json["arch"] = "64 Bits";
    #endif
    return json;
}
