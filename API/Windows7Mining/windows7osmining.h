#ifndef WINDOWS7OSMINING_H
#define WINDOWS7OSMINING_H

#include "API/iStrategy.h"

class Windows7OSMining : public iStrategy
{
public:
    Windows7OSMining();
    QJsonObject getData();
};

#endif // WINDOWS7OSMINING_H
