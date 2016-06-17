#include "notfoundcontroller.h"

NotFoundController::NotFoundController()
{}

void NotFoundController::service(HttpRequest& request, HttpResponse& response)
{
  response.setStatus(404);
  JsonController::service(request, response);
}

QJsonObject NotFoundController::getData()
{
  QJsonObject json;

  json["error"] = "Not found";

  return json;
}
