#include "model/SystemInfo.h"

//Classe para guardar informações do sistema
SystemInfo::SystemInfo()
    : cpuUsagePercent(0), cpuIdlePercent(0), ramUsagePercent(0), ramFreeMB(0), processCount(0) {}

double SystemInfo::getCpuUsagePercent() const { return cpuUsagePercent; }  
double SystemInfo::getCpuIdlePercent() const { return cpuIdlePercent; }     
double SystemInfo::getRamUsagePercent() const { return ramUsagePercent; }
double SystemInfo::getRamFreeMB() const { return ramFreeMB; } 
int SystemInfo::getProcessCount() const { return processCount; }    

void SystemInfo::setCpuUsagePercent(double value) { cpuUsagePercent = value; }  
void SystemInfo::setCpuIdlePercent(double value) { cpuIdlePercent = value; }    
void SystemInfo::setRamUsagePercent(double value) { ramUsagePercent = value; }   
void SystemInfo::setRamFreeMB(double value) { ramFreeMB = value; }               
void SystemInfo::setProcessCount(int value) { processCount = value; }           