#ifndef PROCESSINFO_H
#define PROCESSINFO_H

#include <string>


class ProcessInfo {
public:
    ProcessInfo(int pid = 0, const std::string& name = "", const std::string& user = "",
                double cpuUsage = 0.0, double memoryMB = 0.0, int threads = 0, const std::string& state = "");

    int getPid() const;
    void setPid(int pid);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getUser() const;
    void setUser(const std::string& user);

    double getCpuUsage() const;
    void setCpuUsage(double cpuUsage);

    double getMemoryMB() const;
    void setMemoryMB(double memoryMB);

    int getThreads() const;
    void setThreads(int threads);

    std::string getState() const;
    void setState(const std::string& state);

private:
    int pid;
    std::string name;
    std::string user;
    double cpuUsage;
    double memoryMB;
    int threads;
    std::string state;
    ProcessInfo getProcessDetails(int pid);
};

#endif