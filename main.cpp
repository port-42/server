#include <iostream>
#include <QSysInfo>
#include <QtGlobal>
#include <QJsonObject>

#include "server.h"
#include "dataminingfactory.h"


int main()
{
DataMiningFactory factory = DataMiningFactory();
#ifdef Q_OS_LINUX
    iDataMining *mining = factory.Create(os);
    QJsonObject json = mining->getData();
    std::cout << "OS:" << std::endl;
    std::cout << json["os"].toString().toStdString() << std::endl;
    std::cout << json["distribution"].toString().toStdString() << std::endl;
    std::cout << json["arch"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(memory);
    json = mining->getData();
    std::cout << "Memory:" << std::endl;
    std::cout << json["totalMemory"].toString().toStdString() << std::endl;
    std::cout << json["usedMemory"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(processor);
    json = mining->getData();
    std::cout << "CPU:" << std::endl;
    std::cout << json["model"].toString().toStdString() << std::endl;
    std::cout << json["arch"].toString().toStdString() << std::endl;
    std::cout << json["cores"].toString().toStdString() << std::endl;
    std::cout << json["usage"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(storage);
    json = mining->getData();
    std::cout << "Storage:" << std::endl;
    std::cout << json["disks"].toString().toStdString() << std::endl;
    std::cout << json["total"].toString().toStdString() << std::endl;
    std::cout << json["use"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;
#endif

#ifdef Q_WS_WIN
    std::cout << "How sad, you are on Windows :s" << std::endl;
    switch (QSysInfo::windowsVersion()) {
    case QSysInfo::WV_WINDOWS7:
        std::cout << "yeah Windows 7 !" << std::endl;
        break;
    case QSysInfo::WV_WINDOWS8:
        std::cout << "Windows 8 ? Really ?" << std::endl;
        break;
    case QSysInfo::WV_WINDOWS8_1:
        std::cout << "Windows 8.1 ? Really ?" << std::endl;
        break;
    case QSysInfo::WV_WINDOWS10:
        std::cout << "Windows 10 ? Better than W8 I guess ..." << std::endl;
        break;
    default:
        std::cout << "Too old." << std::endl;
        break;
    }
#endif

}
