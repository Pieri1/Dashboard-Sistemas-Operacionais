#include "model/ProcessManager.h"
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

#include <filesystem>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unordered_map>
#include <vector>

namespace fs = std::filesystem;

ProcessManager::ProcessManager() {}

std::unordered_map<int, unsigned long> previousProcTimes;
unsigned long previousTotalTime = 0;

unsigned long getTotalCpuTime() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);

    std::istringstream ss(line);
    std::string cpu;
    ss >> cpu;

    unsigned long val, total = 0;
    while (ss >> val) total += val;
    return total;
}

unsigned long getProcessCpuTime(int pid) {
    std::ifstream file("/proc/" + std::to_string(pid) + "/stat");
    if (!file.is_open()) return 0;

    std::string token;
    for (int i = 1; i <= 13; ++i) file >> token;
    unsigned long utime = 0, stime = 0;
    file >> utime >> stime;
    return utime + stime;
}

std::vector<ProcessInfo> ProcessManager::getProcessList() {
    std::vector<ProcessInfo> processList;

    unsigned long currentTotalTime = getTotalCpuTime();

    for (const auto& entry : fs::directory_iterator("/proc")) {
        if (!entry.is_directory()) continue;

        std::string pidStr = entry.path().filename().string();
        if (!std::all_of(pidStr.begin(), pidStr.end(), ::isdigit)) continue;

        int pid = std::stoi(pidStr);

        std::string statusPath = "/proc/" + pidStr + "/status";
        std::ifstream statusFile(statusPath);
        if (!statusFile.is_open()) continue;

        std::string name, state;
        int threads = 0;
        double memoryMB = 0.0;

        std::string line;
        while (std::getline(statusFile, line)) {
            if (line.rfind("Name:", 0) == 0) {
                name = line.substr(6);
                name.erase(0, name.find_first_not_of(" \t"));
            } else if (line.rfind("State:", 0) == 0) {
                state = line.substr(7);
                state.erase(0, state.find_first_not_of(" \t"));
            } else if (line.rfind("Threads:", 0) == 0) {
                threads = std::stoi(line.substr(8));
            } else if (line.rfind("VmRSS:", 0) == 0) {
                std::istringstream iss(line.substr(6));
                double kb;
                iss >> kb;
                memoryMB = kb / 1024.0;
            }
        }

        struct stat info;
        std::string procPath = "/proc/" + pidStr;
        if (stat(procPath.c_str(), &info) != 0) continue;

        std::string user = "unknown";
        struct passwd* pw = getpwuid(info.st_uid);
        if (pw) user = pw->pw_name;

        unsigned long currentProcTime = getProcessCpuTime(pid);
        unsigned long lastProcTime = previousProcTimes[pid];
        unsigned long deltaProc = currentProcTime - lastProcTime;
        unsigned long deltaTotal = currentTotalTime - previousTotalTime;

        double cpuUsage = 0.0;
        if (deltaTotal > 0)
            cpuUsage = (double)deltaProc / deltaTotal * 100.0;

        previousProcTimes[pid] = currentProcTime;

        ProcessInfo p(pid, name, user, cpuUsage, memoryMB, threads, state);
        processList.push_back(p);
    }

    previousTotalTime = currentTotalTime;

    return processList;
}

SystemInfo ProcessManager::getSystemInfo() {
    SystemInfo info{};

    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    std::istringstream ss(line);
    std::string cpu;
    ss >> cpu;
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal;
    ss >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
    unsigned long total = user + nice + system + idle + iowait + irq + softirq + steal;
    unsigned long busy = total - idle - iowait;
    info.cpuUsagePercent = (double)busy / total * 100.0;
    info.cpuIdlePercent = (double)(idle + iowait) / total * 100.0;

    std::ifstream memFile("/proc/meminfo");
    std::string memLine;
    unsigned long memTotal = 0, memFree = 0, buffers = 0, cached = 0;
    while (std::getline(memFile, memLine)) {
        std::istringstream memSS(memLine);
        std::string key;
        unsigned long value;
        std::string unit;
        memSS >> key >> value >> unit;
        if (key == "MemTotal:") memTotal = value;
        else if (key == "MemFree:") memFree = value;
        else if (key == "Buffers:") buffers = value;
        else if (key == "Cached:") cached = value;
    }
    unsigned long memUsed = memTotal - memFree - buffers - cached;
    info.ramUsagePercent = (double)memUsed / memTotal * 100.0;
    info.ramFreeMB = memFree / 1024.0;

    int count = 0;
    for (const auto& entry : fs::directory_iterator("/proc")) {
        if (entry.is_directory()) {
            std::string pidStr = entry.path().filename().string();
            if (std::all_of(pidStr.begin(), pidStr.end(), ::isdigit)) {
                ++count;
            }
        }
    }
    info.processCount = count;

    return info;
}

ProcessDetails ProcessManager::getProcessDetails(int pid) {
    ProcessDetails details{};
    details.pid = pid;

    std::ifstream statusFile("/proc/" + std::to_string(pid) + "/status");
    std::string line;
    while (std::getline(statusFile, line)) {
        if (line.rfind("Name:", 0) == 0)
            details.name = line.substr(6);
        else if (line.rfind("State:", 0) == 0)
            details.state = line.substr(6);
        else if (line.rfind("Threads:", 0) == 0)
            details.threads = std::stoi(line.substr(8));
        else if (line.rfind("PPid:", 0) == 0)
            details.ppid = std::stoi(line.substr(6));
        else if (line.rfind("Uid:", 0) == 0) {
            std::istringstream iss(line.substr(5));
            int uid;
            iss >> uid;
            struct passwd* pw = getpwuid(uid);
            if (pw) details.user = pw->pw_name;
        }
        else if (line.rfind("VmRSS:", 0) == 0) {
            std::istringstream iss(line.substr(6));
            double kb;
            iss >> kb;
            details.memoryMB = kb / 1024.0;
        }
        else if (line.rfind("VmSize:", 0) == 0) {
            std::istringstream iss(line.substr(7));
            double kb;
            iss >> kb;
            details.memoryVirtualMB = kb / 1024.0;
        }
        else if (line.rfind("RssAnon:", 0) == 0) {
            // Exemplo de contagem de páginas anônimas (opcional)
            std::istringstream iss(line.substr(8));
            int kb;
            iss >> kb;
            details.pageCount += kb / 4; // 1 página = 4 KB
        }
        // Você pode somar outras páginas (RssFile, RssShmem, etc) se quiser detalhar mais
    }

    // Tempo de CPU
    std::ifstream statFile("/proc/" + std::to_string(pid) + "/stat");
    std::string token;
    for (int i = 1; i <= 13; ++i) statFile >> token;
    unsigned long utime = 0, stime = 0;
    statFile >> utime >> stime;
    long ticks_per_sec = sysconf(_SC_CLK_TCK);
    details.cpuTimeSeconds = double(utime + stime) / ticks_per_sec;

    // Prioridade
    for (int i = 15; i <= 17; ++i) statFile >> token;
    statFile >> details.priority;

    // Arquivos abertos
    std::string fdPath = "/proc/" + std::to_string(pid) + "/fd";
    int openFiles = 0;
    try {
        if (fs::exists(fdPath)) {
            for (auto& entry : fs::directory_iterator(fdPath)) {
                ++openFiles;
            }
        }
    } catch (const std::exception&) {}
    details.openFileCount = openFiles;

    return details;
}