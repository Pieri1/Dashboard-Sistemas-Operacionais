#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <string>
#include <vector>
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

struct ProcessDetails {
    int pid;
    std::string name;
    std::string user;
    std::string cmdline;
    std::string state;
    int threads;
    int ppid;
    long priority;
    double memoryMB;
    int openFileCount;
};

class ProcessManager {
public:
    ProcessManager();
    std::vector<ProcessInfo> getProcessList();
    SystemInfo getSystemInfo();
    ProcessDetails getProcessDetails(int pid);
};

#endif
