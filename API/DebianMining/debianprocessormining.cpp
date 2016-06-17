#include "debianprocessormining.h"

DebianProcessorMining::DebianProcessorMining()
{
}

QJsonObject DebianProcessorMining::getData() {
    QJsonObject json; 
    QProcess p;

    QString model;
    p.start("grep",QStringList() << "model name" << "/proc/cpuinfo");
    p.waitForFinished();
    model = p.readAllStandardOutput();
    model.replace("\t","").replace("model name: ","").replace("\n","");

    QString arch;
    p.start("grep",QStringList() << "lm" << "/proc/cpuinfo");
    p.waitForFinished();
    arch = p.readAllStandardOutput();
    if (arch.isEmpty()) {
        arch = "32 Bits";
    }
    else {
        arch = "64 Bits";
    }

    QString cores;
    p.start("grep",QStringList() << "cpu cores" << "/proc/cpuinfo");
    p.waitForFinished();
    cores = p.readAllStandardOutput();
    cores.replace("\t","").replace("cpu cores: ","").replace("\n","");

    QString usage;
    p.start("bash",QStringList() << "-c" << "top -bn 1 >&1 | grep 'load average' | cut -d ':' -f5 | cut -d ' ' -f2");
    p.waitForFinished();
    usage = p.readAllStandardOutput();
    if ((usage.toFloat() * 100) == 0) {
        usage.replace(",\n","").replace(",",".");
        p.start("bash",QStringList() << "-c" << "top -bn 1 >&1 | grep 'load average' | cut -d ':' -f4 | cut -d ' ' -f2");
        p.waitForFinished();
        usage = p.readAllStandardOutput();
        usage.replace(",\n","").replace(",",".");
    }
    usage = QString::number(usage.toFloat() * 100) + "%";

    json["model"] = model;
    json["architecture"]  = arch;
    json["count"] = cores;
    json["usage"] = usage;

    return json;
}
