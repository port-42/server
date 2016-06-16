#ifndef NOTFOUNDCONTROLLER_H
#define NOTFOUNDCONTROLLER_H

#include "jsoncontroller.h"

/**
  This controller dumps the received HTTP request in the response.
*/

class NotFoundController : public JsonController {
    Q_OBJECT
    Q_DISABLE_COPY(NotFoundController)
public:
    /** Constructor */
    NotFoundController();
    void service(HttpRequest& request, HttpResponse& response);
 protected:
    QJsonObject getData();
};

#endif // NOTFOUNDCONTROLLER_H
