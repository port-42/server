#ifndef WINDOWS7STORAGEMINING_H
#define WINDOWS7STORAGEMINING_H

#include "../iStrategy.h"
#include <QtGlobal>

#if QT_VERSION >= 0x050400
#include <QStorageInfo>
#endif

class Windows7StorageMining : public iStrategy
{
public:
    Windows7StorageMining();
    QJsonObject getData();
};

#endif // WINDOWS7STORAGEMINING_H
