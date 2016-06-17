#include <QCoreApplication>
#include "requestmapper.h"
#include "controller/maincontroller.h"

RequestMapper::RequestMapper(QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("RequestMapper: created");
}

RequestMapper::~RequestMapper()
{
    qDebug("RequestMapper: deleted");
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    DataMiningFactory factory = DataMiningFactory();

    if (path.startsWith("/os"))
    {
      MainController(factory, os).service(request, response);
    }

    else if (path.startsWith("/cpu"))
    {
      MainController(factory, processor).service(request, response);
    }

    else if (path.startsWith("/ram"))
    {
      MainController(factory, memory).service(request, response);
    }

    else if (path.startsWith("/hdd"))
    {
      MainController(factory, storage).service(request, response);
    }

    // If nothing is found you don't respect the API
    else
    {}

    qDebug("RequestMapper: finished request");
}
