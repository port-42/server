#ifndef WINDOWS10OSMINING_H
#define WINDOWS10OSMINING_H

#include "API/iStrategy.h"
#include <QtGlobal>

class Windows10OSMining : public iStrategy
{
public:
    Windows10OSMining();
    QJsonObject getData();
};

#endif // WINDOWS10OSMINING_H
