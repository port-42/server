#ifndef DEBIANOSMINING_H
#define DEBIANOSMINING_H

#include <sys/utsname.h>

#include "iStrategy.h"

class DebianOsMining : public iStrategy
{
public:
    DebianOsMining();
    QJsonObject getData();
};

#endif // DEBIANOSMINING_H
