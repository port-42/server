#include "maincontroller.h"

MainController::MainController()
{}

MainController::MainController(DataMiningFactory factory, dataType type) : m_factory{factory}, m_type(type) {}

void MainController::initHeader(HttpResponse& response)
{
  response.setHeader("Content-Type", "application/json; charset=UTF-8");
}

void MainController::service(HttpRequest& request, HttpResponse& response)
{
  this->initHeader(response);
  QJsonDocument doc(this->getData());
  QByteArray strJson(doc.toJson());
  response.write(strJson, true);
}

QJsonObject MainController::getData()
{
  QJsonObject json;

  iDataMining *mining = m_factory.Create(m_type);

  return mining->getData();
}
