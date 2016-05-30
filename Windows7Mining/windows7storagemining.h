#ifndef WINDOWS7STORAGEMINING_H
#define WINDOWS7STORAGEMINING_H

#include "iStrategy.h"
#include <QStorageInfo>

class Windows7StorageMining : public iStrategy
{
public:
    Windows7StorageMining();
    QJsonObject getData();
};

#endif // WINDOWS7STORAGEMINING_H
