#ifndef WINDOWS10MEMORYMINING_H
#define WINDOWS10MEMORYMINING_H

#include "iStrategy.h"

class Windows10MemoryMining : public iStrategy
{
public:
    Windows10MemoryMining();
    QJsonObject getData();
};

#endif // WINDOWS10MEMORYMINING_H
