#ifndef OSMINING_H
#define OSMINING_H

#include "iDataMining.h"
#include "iStrategy.h"

class Mining : public iDataMining
{
private:
    iStrategy *strategy;
public:
    Mining();
    QJsonObject getData();
    void setStrategy(iStrategy *strategy);
};

#endif // OSMINING_H
