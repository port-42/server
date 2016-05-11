#ifndef DEBIANPROCESSORMINING_H
#define DEBIANPROCESSORMINING_H

#include "iStrategy.h"

class DebianProcessorMining : public iStrategy
{
public:
    DebianProcessorMining();
    QJsonObject getData();
};

#endif // DEBIANPROCESSORMINING_H
