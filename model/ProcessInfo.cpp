#include "ProcessInfo.h"

ProcessInfo::ProcessInfo(int pid, const std::string& name, const std::string& user, double cpuUsage, double memoryMB, int threads, const std::string& state)
    : pid(pid), name(name), user(user), cpuUsage(cpuUsage), memoryMB(memoryMB), threads(threads), state(state) {}
int ProcessInfo::getPid() const {
    return pid;
}

void ProcessInfo::setPid(int pid) {
    this->pid = pid;
}

std::string ProcessInfo::getName() const {
    return name;
}

void ProcessInfo::setName(const std::string& name) {
    this->name = name;
}

std::string ProcessInfo::getUser() const {
    return user;
}

void ProcessInfo::setUser(const std::string& user) {
    this->user = user;
}

double ProcessInfo::getCpuUsage() const {
    return cpuUsage;
}

void ProcessInfo::setCpuUsage(double cpuUsage) {
    this->cpuUsage = cpuUsage;
}

double ProcessInfo::getMemoryMB() const {
    return memoryMB;
}

void ProcessInfo::setMemoryMB(double memoryMB) {
    this->memoryMB = memoryMB;
}

int ProcessInfo::getThreads() const {
    return threads;
}

void ProcessInfo::setThreads(int threads) {
    this->threads = threads;
}

std::string ProcessInfo::getState() const {
    return state;
}

void ProcessInfo::setState(const std::string& state) {
    this->state = state;
}


