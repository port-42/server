#include <QJsonDocument>
#include "jsoncontroller.h"

JsonController::JsonController()
{}

void JsonController::initHeader(HttpResponse& response)
{
  response.setHeader("Content-Type", "application/json; charset=UTF-8");
}

void JsonController::service(HttpRequest& request, HttpResponse& response)
{
  this->initHeader(response);
  QJsonDocument doc(this->getData());
  QByteArray strJson(doc.toJson());
  response.write(strJson, true);
}
