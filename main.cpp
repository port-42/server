#include <iostream>
#include <QCoreApplication>
#include <QSysInfo>
#include <QtGlobal>
#include <QJsonObject>
#include <httplistener.h>
#include <requestmapper.h>

#include "server.h"
#include "dataminingfactory.h"

QString getConfigFileName() {
  QString binDir=QCoreApplication::applicationDirPath();
  QString appName=QCoreApplication::applicationName();
  QString fileName(appName+".ini");
  QFile file(binDir+"/"+fileName);
  return (file.exists()) ? fileName : NULL;
}

int main(int argc, char *argv[])
  QCoreApplication app(argc,argv);

  app.setApplicationName("Port-Server");
  app.setOrganizationName("port-42");

  QString configFileName = getConfigFileName();

  // Configure and start the TCP listener
  QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
  listenerSettings->beginGroup("listener");

  new HttpListener(listenerSettings, new RequestMapper(&app),&app);

  qWarning("Server has started");

  app.exec();

  qWarning("Server has stopped");


  /* DATA RETRIVAL CODE TEST */
  /*
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
  */
}
