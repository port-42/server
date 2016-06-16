#include "oscontroller.h"

OsController::OsController()
{}

QJsonObject OsController::getData()
{
  QJsonObject json;

  json["error"] = "OS need to be implemented";

  return json;
}
