#ifndef WINDOWS10PROCESSORMINING_H
#define WINDOWS10PROCESSORMINING_H

#include "iStrategy.h"

class Windows10ProcessorMining : public iStrategy
{
public:
    Windows10ProcessorMining();
    QJsonObject getData();
};

#endif // WINDOWS10PROCESSORMINING_H
