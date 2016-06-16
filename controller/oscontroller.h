#ifndef OSCONTROLLER_H
#define OSCONTROLLER_H

#include "jsoncontroller.h"

/**
  This controller dumps the received HTTP request in the response.
*/

class OsController : public JsonController {
    Q_OBJECT
    Q_DISABLE_COPY(OsController)
public:
    /** Constructor */
    OsController();
protected:
    QJsonObject getData();
};

#endif // OSCONTROLLER_H
