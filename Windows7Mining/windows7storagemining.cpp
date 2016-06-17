#include "windows7storagemining.h"

Windows7StorageMining::Windows7StorageMining()
{
}

QJsonObject Windows7StorageMining::getData() {
    QJsonObject json;
    int disks = 0;
    double total = 0;
    double use = 0;
    #if QT_VERSION >= 0x050400
    for (auto volume : QStorageInfo::mountedVolumes()) {
        if (volume.fileSystemType() == "NTFS"  && volume.isValid()) {
            disks++;
            total += volume.bytesTotal();
            use += (volume.bytesTotal() - volume.bytesAvailable());
        }
    }
    #endif
    json["disks"] = QString::number(disks);
    json["total"] = QString::number(total / (1024 * 1024 * 1024)) + " Go";
    json["use"] = QString::number(use / (1024 * 1024 * 1024)) + " Go";
    return json;
}
