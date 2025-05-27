#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include <QObject>
#include <QTimer>
#include "view/MainWindow.h"
#include "model/ProcessManager.h"

class DashboardController : public QObject {
    Q_OBJECT

public:
    explicit DashboardController(MainWindow* mainWindow, QObject* parent = nullptr);
    void start();

private slots:
    void updateData();

private:
    MainWindow* view;
    ProcessManager processManager;
    QTimer timer;
};

#endif