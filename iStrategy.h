#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include <string>
#include <QJsonObject>

class iStrategy {
public:
    virtual QJsonObject getData() = 0;
    ~iStrategy();
};

#endif //ISTRATEGY_H
