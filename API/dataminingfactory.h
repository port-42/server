#ifndef DATAMININGFACTORY_H
#define DATAMININGFACTORY_H
#include "../server.h"
#include "iDataMining.h"
#include "mining.h"
#include "DebianMining/debianosmining.h"
#include "DebianMining/debianmemorymining.h"
#include "DebianMining/debianprocessormining.h"
#include "DebianMining/debianstoragemining.h"
#include "Windows10Mining/windows10memorymining.h"
#include "Windows10Mining/windows10osmining.h"
#include "Windows10Mining/windows10processormining.h"
#include "Windows10Mining/windows10storagemining.h"
#include "Windows7Mining/windows7memorymining.h"
#include "Windows7Mining/windows7osmining.h"
#include "Windows7Mining/windows7processormining.h"
#include "Windows7Mining/windows7storagemining.h"
#include <QtGlobal>
#include <string>


class DataMiningFactory
{
public:
    DataMiningFactory();
    iDataMining *Create(dataType os);
};

#endif // DATAMININGFACTORY_H
