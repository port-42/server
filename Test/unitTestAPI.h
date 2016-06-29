#ifndef UNITTESTAPI_H
#define UNITTESTAPI_H

#include <QtTest/QTest>
#include "API/dataminingfactory.h"

class unitTestAPI: public QObject
{
    Q_OBJECT
private slots:
    void testCPU();
    void testOS();
    void testRAM();
    void testDISK();
};

#endif // UNITTESTAPI_H
