#ifndef WINDOWS10STORAGEMINING_H
#define WINDOWS10STORAGEMINING_H

#include "API/iStrategy.h"
#if QT_VERSION >= 0x050400
#include <QStorageInfo>
#endif

class Windows10StorageMining : public iStrategy
{
public:
    Windows10StorageMining();
    QJsonObject getData();
};

#endif // WINDOWS10STORAGEMINING_H
