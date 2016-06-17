#ifndef IDATAMINING_H
#define IDATAMINING_H

#include "iStrategy.h"

class iDataMining
{
public:
    virtual void setStrategy(iStrategy *strategy) = 0;
    virtual QJsonObject getData() = 0;
};

#endif //IDATAMINING_H
