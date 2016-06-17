#include "debianmemorymining.h"

DebianMemoryMining::DebianMemoryMining()
{
}

QJsonObject DebianMemoryMining::getData() {
    QJsonObject json;
    QProcess p;

    QString totalMemory;
    p.start("grep",QStringList() << "MemTotal" << "/proc/meminfo");
    p.waitForFinished();
    totalMemory = p.readAllStandardOutput();
    totalMemory.replace(" ","").replace("MemTotal:","").replace("kB","");

    QString MemFree;
    p.start("grep",QStringList() << "MemFree" << "/proc/meminfo");
    p.waitForFinished();
    MemFree = p.readAllStandardOutput();
    MemFree.replace(" ","").replace("MemFree:","").replace("kB","");

    QString Buffers;
    p.start("grep",QStringList() << "Buffers" << "/proc/meminfo");
    p.waitForFinished();
    Buffers = p.readAllStandardOutput();
    Buffers.replace(" ","").replace("Buffers:","").replace("kB","");

    QString Cached;
    p.start("grep",QStringList() << "Cached" << "/proc/meminfo");
    p.waitForFinished();
    Cached = p.readAllStandardOutput();
    Cached.replace(" ","").replace("Cached:","").replace("kB","");

    int usedMemory_i = totalMemory.toInt() - MemFree.toInt() - Buffers.toInt() - Cached.toInt();
    QString usedMemory = QString::number(usedMemory_i);

    totalMemory = QString::number(totalMemory.toInt() / 1024) + " Mo";
    usedMemory = QString::number(usedMemory.toInt() / 1024) + " Mo";

    json["total"] = totalMemory;
    json["usage"] = usedMemory;
    return json;
}

