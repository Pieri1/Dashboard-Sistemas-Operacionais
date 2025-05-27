#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <vector>
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

class ProcessManager {
public:
    ProcessManager();
    std::vector<ProcessInfo> getProcessList();
    SystemInfo getSystemInfo();
};

#endif
