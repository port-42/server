#include <iostream>
#include <QCoreApplication>
#include <QSysInfo>
#include <QtGlobal>
#include <QJsonObject>
#include <httplistener.h>
#include "requestmapper.h"

#include "server.h"

QString getConfigFileName() {
  QString binDir = QCoreApplication::applicationDirPath();
  QString appName = QCoreApplication::applicationName();
  QString fileName(appName+".ini");
  QFile file(binDir+"/"+fileName);

  return (file.exists()) ? fileName : NULL;
}

int main(int argc, char *argv[])
{
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
}
