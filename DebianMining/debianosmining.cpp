#include "debianosmining.h"

DebianOsMining::DebianOsMining()
{
}

QJsonObject DebianOsMining::getData() {
    int z;
    struct utsname u_name;
    z = uname(&u_name);
    QJsonObject json;
    if (z == -1) {
        json["err"] = "uname error";
    }
    else {
        json["os"] = u_name.sysname;
        json["distribution"] = u_name.nodename;
        json["arch"] = u_name.machine;
    }
    return json;

}
