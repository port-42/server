#ifndef DEBIANPROCESSORMINING_H
#define DEBIANPROCESSORMINING_H

#include "API/iStrategy.h"
#include <QProcess>

class DebianProcessorMining : public iStrategy
{
public:
    DebianProcessorMining();
    QJsonObject getData();
};

#endif // DEBIANPROCESSORMINING_H
