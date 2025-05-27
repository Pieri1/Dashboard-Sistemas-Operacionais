#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTableWidgetItem>
#include <QString>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateProcessList(const std::vector<ProcessInfo>& processes) {
    ui->tblProcess->setRowCount(processes.size());

    for (int i = 0; i < processes.size(); ++i) {
        const auto& p = processes[i];

        ui->tblProcess->setItem(i, 0, new QTableWidgetItem(QString::number(p.getPid())));
        ui->tblProcess->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
        ui->tblProcess->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.getUser())));
        ui->tblProcess->setItem(i, 3, new QTableWidgetItem(QString::number(p.getCpuUsage(), 'f', 2) + "%"));
        ui->tblProcess->setItem(i, 4, new QTableWidgetItem(QString::number(p.getMemoryMB(), 'f', 1) + " MB"));
        ui->tblProcess->setItem(i, 5, new QTableWidgetItem(QString::number(p.getThreads())));
        ui->tblProcess->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(p.getState())));
    }

    // Opcional: redimensionar colunas para caberem no conteúdo
    ui->tblProcess->resizeColumnsToContents();
    ui->lblUpdate->setText(QString("Última atualização: %1").arg(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss")));
}

void MainWindow::updateSystemInfo(const SystemInfo& info) {
    ui->lblCpuUse->setText(QString("Uso de CPU: %1%").arg(QString::number(info.cpuUsagePercent, 'f', 2)));
    ui->lblCpuIdle->setText(QString("CPU Ociosa: %1%").arg(QString::number(info.cpuIdlePercent, 'f', 2)));
    ui->lblMemUse->setText(QString("Uso de RAM: %1%").arg(QString::number(info.ramUsagePercent, 'f', 2)));
    ui->lblMemFree->setText(QString("RAM Livre: %1 MB").arg(QString::number(info.ramFreeMB, 'f', 1)));
    ui->lblTotalProc->setText(QString("Processos: %1").arg(info.processCount));
}