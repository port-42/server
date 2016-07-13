#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QJsonObject>
#include <QJsonDocument>
#include "../API/dataminingfactory.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"

/**
  This controller dumps the received HTTP request in the response.
*/

class MainController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(MainController)
public:
    /** Constructor */
    MainController();
    MainController(DataMiningFactory factory, dataType type);
    void service(HttpRequest& request, HttpResponse& response);

 protected:
    DataMiningFactory m_factory;
    dataType m_type;

    void initHeader(HttpResponse& response);
    QJsonObject getData();
};

#endif // MAINCONTROLLER_H
