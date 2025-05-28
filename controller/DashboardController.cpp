#include "controller/DashboardController.h"
#include "view/MainWindow.h"
#include "view/ProcessDetailDialog.h"

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

void DashboardController::showProcessDetails(int pid) {
    ProcessDetails details = processManager.getProcessDetails(pid); // Implemente esse método se não existir
    ProcessDetailDialog dialog;
    dialog.setProcessDetails(details);
    dialog.exec();
}