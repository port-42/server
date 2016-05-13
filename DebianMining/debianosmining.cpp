#include "debianosmining.h"

#ifdef Q_OS_LINUX
#include <sys/utsname.h>
#endif

DebianOsMining::DebianOsMining()
{
}

QJsonObject DebianOsMining::getData() {
    QJsonObject json;

    #ifdef Q_OS_LINUX
    int z;
    struct utsname u_name;

    z = uname(&u_name);
    if (z == -1) {
        json["err"] = "uname error";
    }
    else {
        json["os"] = u_name.sysname;
        json["version"] = u_name.nodename;
        json["arch"] = u_name.machine;
    }
    #endif
    return json;
}
