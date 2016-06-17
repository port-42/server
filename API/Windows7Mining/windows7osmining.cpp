#include "windows7osmining.h"

Windows7OSMining::Windows7OSMining()
{
}

QJsonObject Windows7OSMining::getData() {
    QJsonObject json;
    json["name"] = "Windows";
    json["version"] = "7";
    #ifdef Q_OS_WIN32
    json["architecture"] = "32 Bits";
    #endif
    #ifdef Q_OS_WIN64
    json["architecture"] = "64 Bits";
    #endif
    return json;
}
