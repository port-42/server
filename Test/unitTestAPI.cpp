#include "unitTestAPI.h"

void unitTestAPI::testCPU()
{
    DataMiningFactory factory;
    iDataMining *mining = factory.Create(os);
    QJsonObject json = mining->getData();
    QVERIFY(json["name"] != "");
    QVERIFY(json["version"] != "");
    QVERIFY(json["architecture"] != "");
}
void unitTestAPI::testDISK()
{
    DataMiningFactory factory;
    iDataMining *mining = factory.Create(cpu);
    QJsonObject json = mining->getData();
    QVERIFY(json["model"] != "");
    QVERIFY(json["architecture"] != "");
    QVERIFY(json["count"] != "");
    QVERIFY(json["usage"] != "");
}
void unitTestAPI::testOS()
{
    DataMiningFactory factory;
    iDataMining *mining = factory.Create(ram);
    QJsonObject json = mining->getData();
    QVERIFY(json["total"] != "");
    QVERIFY(json["usage"] != "");
}
void unitTestAPI::testRAM()
{
    DataMiningFactory factory;
    iDataMining *mining = factory.Create(hdd);
    QJsonObject json = mining->getData();
    QVERIFY(json["count"] != "");
    QVERIFY(json["total"] != "");
    QVERIFY(json["usage"] != "");
}

QTEST_MAIN(unitTestAPI)
