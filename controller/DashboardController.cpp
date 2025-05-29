#include "controller/DashboardController.h"
#include "view/MainWindow.h"
#include "view/ProcessDetailDialog.h"
#include "model/Worker.h"
#include <QThread>

// DashboardController serve para comunicar o dashboard (MainWindow e ProcessDetailDialog) com o modelo de dados (ProcessManager)

// Inicializa o worker e sua thread, conectando os sinais para recepção de dados para atualização da interface
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

// Encerra a thread do worker e libera recursos ao destruir o controller
DashboardController::~DashboardController() {
    workerThread->quit();
    workerThread->wait();
    delete worker;
}

// Exibe os detalhes de um processo especifico no ProcessDetailDialog
void DashboardController::showProcessDetails(int pid) {
    ProcessDetails details = processManager.getProcessDetails(pid);
    ProcessDetailDialog dialog;
    dialog.setProcessDetails(details);
    dialog.exec();
}