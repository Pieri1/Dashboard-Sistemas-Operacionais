#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <string>
#include <vector>
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

//Struct para guardar detalhes avançados de um processo (Mostrados no dialog)
struct ProcessDetails {
    int pid;             
    std::string name;     
    std::string user;        
    std::string state;    
    int threads;         
    int ppid;            
    long priority;          
    double memoryMB;       
    double memoryVirtualMB;  
    double cpuTimeSeconds; 
    int openFileCount;
    int pageCount;
};

class ProcessManager {
public:
    ProcessManager();               
    std::vector<ProcessInfo> getProcessList();        
    SystemInfo getSystemInfo();                     
    ProcessDetails getProcessDetails(int pid);       
};

#endif
