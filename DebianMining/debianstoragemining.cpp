#include "debianstoragemining.h"

DebianStorageMining::DebianStorageMining()
{
}

QJsonObject DebianStorageMining::getData() {
    QJsonObject json;
    QProcess p;

    QString disks;
    p.start("bash",QStringList() << "-c" << "df | grep '/dev/sd' | wc -l");
    p.waitForFinished();
    disks = p.readAllStandardOutput();
    disks.replace("\n","");

    QString total;
    p.start("bash",QStringList() << "-c" << "df --total | grep 'total' | tr -s ' ' | cut -d ' ' -f2");
    p.waitForFinished();
    total = p.readAllStandardOutput();
    total = QString::number(total.toFloat() / (1024 * 1024)) + " Go";

    QString use;
    p.start("bash",QStringList() << "-c" << "df --total | grep 'total' | tr -s ' ' | cut -d ' ' -f3");
    p.waitForFinished();
    use = p.readAllStandardOutput();
    use = QString::number(use.toFloat() / (1024 * 1024)) + " Go";

    json["count"] = disks;
    json["total"] = total;
    json["usage"] = use;

    return json;
}
