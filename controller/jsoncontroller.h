#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QJsonObject>
#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"

/**
  This controller dumps the received HTTP request in the response.
*/

class JsonController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(JsonController)
public:

    /** Constructor */
    JsonController();

    /** Generates the response */
    void service(HttpRequest& request, HttpResponse& response);
 protected:
    void initHeader(HttpResponse& response);
    virtual QJsonObject getData() = 0;
};

#endif // JSONCONTROLLER_H
