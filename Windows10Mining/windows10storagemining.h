#ifndef WINDOWS10STORAGEMINING_H
#define WINDOWS10STORAGEMINING_H

#include "iStrategy.h"

class Windows10StorageMining : public iStrategy
{
public:
    Windows10StorageMining();
    QJsonObject getData();
};

#endif // WINDOWS10STORAGEMINING_H
