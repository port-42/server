#include "windows10osmining.h"

Windows10OSMining::Windows10OSMining()
{
}

QJsonObject Windows10OSMining::getData() {
    QJsonObject json;
    json["name"] = "Windows";
    json["version"] = "10";
    #ifdef Q_OS_WIN32
    json["architecture"] = "32 Bits";
    #endif
    #ifdef Q_OS_WIN64
    json["architecture"] = "64 Bits";
    #endif
    return json;
}
