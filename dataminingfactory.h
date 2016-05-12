#ifndef DATAMININGFACTORY_H
#define DATAMININGFACTORY_H
#include "server.h"
#include "iDataMining.h"
#include "mining.h"
#include "DebianMining/debianosmining.h"
#include "DebianMining/debianmemorymining.h"
#include "DebianMining/debianprocessormining.h"
#include "DebianMining/debianstoragemining.h"
#include <string>


class DataMiningFactory
{
public:
    DataMiningFactory();
    iDataMining *Create(dataType os);
};

#endif // DATAMININGFACTORY_H
