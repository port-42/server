#include "dataminingfactory.h"


DataMiningFactory::DataMiningFactory()
{
}

iDataMining *DataMiningFactory::Create(dataType dType) {
    iDataMining *mining = new Mining();
    #ifdef Q_OS_LINUX
    if (dType == os) {
        iStrategy *strategy = new DebianOsMining();
        mining->setStrategy(strategy);
    }
    else if (dType == processor) {
        iStrategy *strategy = new DebianProcessorMining();
        mining->setStrategy(strategy);
    }
    else if (dType == memory) {
        iStrategy *strategy = new DebianMemoryMining();
        mining->setStrategy(strategy);
    }
    else if (dType == storage) {
        iStrategy *strategy = new DebianStorageMining();
        mining->setStrategy(strategy);
    }
    #endif

    #ifdef Q_OS_WIN
    if (QSysInfo::windowsVersion() == QSysInfo::WV_WINDOWS10) {
        if (dType == os) {
            iStrategy *strategy = new Windows10OSMining();
            mining->setStrategy(strategy);
        }
        else if (dType == processor) {
            iStrategy *strategy = new Windows10ProcessorMining();
            mining->setStrategy(strategy);
        }
        else if (dType == memory) {
            iStrategy *strategy = new Windows10MemoryMining();
            mining->setStrategy(strategy);
        }
        else if (dType == storage) {
            iStrategy *strategy = new Windows10StorageMining();
            mining->setStrategy(strategy);
        }
    }

    #endif

    return mining;
}
