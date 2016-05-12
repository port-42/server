#ifndef DEBIANSTORAGEMINING_H
#define DEBIANSTORAGEMINING_H

#include "iStrategy.h"

class DebianStorageMining : public iStrategy
{
public:
    DebianStorageMining();
    QJsonObject getData();
};

#endif // DEBIANSTORAGEMINING_H
