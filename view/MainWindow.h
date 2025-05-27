#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateProcessList(const std::vector<ProcessInfo>& processes);
    void updateSystemInfo(const SystemInfo& info);

private:
    Ui::MainWindow *ui;
};

#endif