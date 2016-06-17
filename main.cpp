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
    std::cout << json["name"].toString().toStdString() << std::endl;
    std::cout << json["version"].toString().toStdString() << std::endl;
    std::cout << json["architecture"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(ram);
    json = mining->getData();
    std::cout << "Memory:" << std::endl;
    std::cout << json["total"].toString().toStdString() << std::endl;
    std::cout << json["usage"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(cpu);
    json = mining->getData();
    std::cout << "CPU:" << std::endl;
    std::cout << json["model"].toString().toStdString() << std::endl;
    std::cout << json["architecture"].toString().toStdString() << std::endl;
    std::cout << json["count"].toString().toStdString() << std::endl;
    std::cout << json["usage"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;

    mining = factory.Create(hdd);
    json = mining->getData();
    std::cout << "Storage:" << std::endl;
    std::cout << json["count"].toString().toStdString() << std::endl;
    std::cout << json["total"].toString().toStdString() << std::endl;
    std::cout << json["usage"].toString().toStdString() << std::endl;
    std::cout << "" << std::endl;
}
