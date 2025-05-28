#include "view/ProcessDetailDialog.h"
#include "ui_ProcessDetailDialog.h"

ProcessDetailDialog::ProcessDetailDialog(QWidget *parent) 
    : QDialog(parent), ui(new Ui::ProcessDetailDialog) {
    ui->setupUi(this);

    connect(ui->btnClose, &QPushButton::clicked, this, &ProcessDetailDialog::close);
}

void ProcessDetailDialog::setProcessDetails(const ProcessDetails& d) {
    ui->lblPId->setText("PID: " + QString::number(d.pid));
    ui->lblName->setText("Nome: " + QString::fromStdString(d.name));
    ui->lblUser->setText("Usuário: " + QString::fromStdString(d.user));
    ui->lblThreads->setText("Threads: " + QString::number(d.threads));
    ui->lblState->setText("Estado: " + QString::fromStdString(d.state));
    ui->lblParent->setText("PPID: " + QString::number(d.ppid));
    ui->lblCpuTime->setText("Tempo de CPU: " + QString::number(d.cpuTimeSeconds, 'f', 2) + " s");
    ui->lblMemVirtual->setText("Memória Virtual: " + QString::number(d.memoryVirtualMB, 'f', 1) + " MB");
    ui->lblMemRam->setText("Memória RAM: " + QString::number(d.memoryMB, 'f', 1) + " MB");
    ui->lblPriority->setText("Prioridade: " + QString::number(d.priority));
    ui->lblFiles->setText("Arquivos abertos: " + QString::number(d.openFileCount));
    ui->lblPages->setText("Páginas: " + QString::number(d.pageCount));
}


ProcessDetailDialog::~ProcessDetailDialog()
{
    delete ui;
}