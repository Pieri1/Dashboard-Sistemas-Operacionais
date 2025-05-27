#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

struct SystemInfo {
    double cpuUsagePercent;
    double cpuIdlePercent;
    double ramUsagePercent;
    double ramFreeMB;
    int processCount;

    SystemInfo();

    // Getters
    double getCpuUsagePercent() const;
    double getCpuIdlePercent() const;
    double getRamUsagePercent() const;
    double getRamFreeMB() const;
    int getProcessCount() const;

    // Setters
    void setCpuUsagePercent(double value);
    void setCpuIdlePercent(double value);
    void setRamUsagePercent(double value);
    void setRamFreeMB(double value);
    void setProcessCount(int value);
};

#endif