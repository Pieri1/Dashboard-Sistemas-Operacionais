#include "controller/DashboardController.h"
#include "view/MainWindow.h"
#include "view/ProcessDetailDialog.h"
#include "model/Worker.h"
#include <QThread>

DashboardController::DashboardController(MainWindow* mainWindow, QObject* parent)
    : QObject(parent), view(mainWindow) {
    workerThread = new QThread(this);
    worker = new Worker(&processManager);
    worker->moveToThread(workerThread);

    connect(workerThread, &QThread::started, worker, &Worker::start);
    connect(worker, &Worker::processListReady, view, &MainWindow::updateProcessList);
    connect(worker, &Worker::systemInfoReady, view, &MainWindow::updateSystemInfo);

    workerThread->start();
}

DashboardController::~DashboardController() {
    workerThread->quit();
    workerThread->wait();
    delete worker;
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