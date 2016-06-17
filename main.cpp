#include <iostream>
#include <QSysInfo>
#include <QtGlobal>
#include <QJsonObject>

#include "server.h"
#include "dataminingfactory.h"

int main()
{
    DataMiningFactory factory = DataMiningFactory();
    iDataMining *mining = factory.Create(os);
    QJsonObject json = mining->getData();
    std::cout << "OS:" << std::endl;
    std::cout << json["os"].toString().toStdString() << std::endl;
    std::cout << json["version"].toString().toStdString() << std::endl;
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
}
