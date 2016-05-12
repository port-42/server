#ifndef WINDOWS7PROCESSORMINING_H
#define WINDOWS7PROCESSORMINING_H

#include "iStrategy.h"

class Windows7ProcessorMining : public iStrategy
{
public:
    Windows7ProcessorMining();
    QJsonObject getData();
};

#endif // WINDOWS7PROCESSORMINING_H
