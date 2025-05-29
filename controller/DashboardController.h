#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "model/ProcessManager.h"
#include "model/Worker.h"

class MainWindow;

class DashboardController : public QObject {
    Q_OBJECT
public:
    explicit DashboardController(MainWindow* mainWindow, QObject* parent = nullptr);
    ~DashboardController();
    void showProcessDetails(int pid);

private:
    MainWindow* view;
    ProcessManager processManager;
    QThread* workerThread;
    Worker* worker;
    QTimer timer;
};

#endif