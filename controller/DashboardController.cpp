#include "controller/DashboardController.h"
#include "view/MainWindow.h"

DashboardController::DashboardController(MainWindow* mainWindow, QObject* parent)
    : QObject(parent), view(mainWindow) {
    connect(&timer, &QTimer::timeout, this, &DashboardController::updateData);
}

void DashboardController::start() {
    timer.start(5000); // 5 segundos
    updateData(); 
}

void DashboardController::updateData(){
    std::vector<ProcessInfo> list = processManager.getProcessList();
    view->updateProcessList(list);
    SystemInfo info = processManager.getSystemInfo();
    view->updateSystemInfo(info);
}