#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

namespace Ui {
class MainWindow;
}

class DashboardController; // Forward declaration

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, DashboardController* controller = nullptr);
    ~MainWindow();

    void updateProcessList(const std::vector<ProcessInfo>& processes);
    void updateSystemInfo(const SystemInfo& info);
    void setDashboardController(DashboardController* controller);

private slots:
    void onProcessRowDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    DashboardController* dashboardController; // Adicione esta linha
};

#endif