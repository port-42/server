#include <QCoreApplication>
#include "requestmapper.h"
#include "controller/oscontroller.h"
#include "controller/notfoundcontroller.h"
/*
#include "controller/cpucontroller.h"
#include "controller/ramcontroller.h"
#include "controller/hddcontroller.h"
*/

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

    // For the following pathes, each request gets its own new instance of the related controller.

    /*
    if (path.startsWith("/os"))
    {
        OsController().service(request, response);
    }

    else if (path.startsWith("/cpu"))
    {
        CpuController().service(request, response);
    }

    else if (path.startsWith("/ram"))
    {
        RamController().service(request, response);
    }

    else if (path.startsWith("/hdd"))
    {
        HddController().service(request, response);
    }
    */
    // If nothing is found
    /*    else
    { */
      NotFoundController().service(request, response);
      /* } */

    qDebug("RequestMapper: finished request");

    // Clear the log buffer
    /*
    if (logger)
    {
       logger->clear();
    }
    */
}
