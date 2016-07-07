#ifndef DEBIANMEMORYMINING_H
#define DEBIANMEMORYMINING_H

#include "../iStrategy.h"
#include <QProcess>

class DebianMemoryMining : public iStrategy
{
public:
    DebianMemoryMining();
    QJsonObject getData();
};

#endif // DEBIANMEMORYMINING_H
