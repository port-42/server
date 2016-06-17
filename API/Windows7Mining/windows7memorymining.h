#ifndef WINDOWS7MEMORYMINING_H
#define WINDOWS7MEMORYMINING_H

#include "API/iStrategy.h"

class Windows7MemoryMining : public iStrategy
{
public:
    Windows7MemoryMining();
    QJsonObject getData();
};

#endif // WINDOWS7MEMORYMINING_H
