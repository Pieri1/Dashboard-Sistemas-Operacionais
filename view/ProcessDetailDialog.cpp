#include "view/ProcessDetailDialog.h"
#include "ui_ProcessDetailDialog.h"

ProcessDetailDialog::ProcessDetailDialog(QWidget *parent) 
    : QDialog(parent), ui(new Ui::ProcessDetailDialog) {
    ui->setupUi(this);

    connect(ui->btnClose, &QPushButton::clicked, this, &ProcessDetailDialog::close);
}

void ProcessDetailDialog::setProcessDetails(const ProcessDetails& d) {
    ui->lblPId->setText(QString::number(d.pid));
    ui->lblName->setText(QString::fromStdString(d.name));
    ui->lblUser->setText(QString::fromStdString(d.user));
    ui->lblThreads->setText(QString::number(d.threads));
    ui->lblState->setText(QString::fromStdString(d.state));
    ui->lblParent->setText(QString::number(d.ppid));
    //ui cpu time
    //ui mem virtual
    //ui mem ram
    //ui->lblMem->setText(QString::number(d.memoryMB, 'f', 1) + " MB");
    ui->lblPriority->setText(QString::number(d.priority));
    ui->lblFiles->setText(QString::number(d.openFileCount));
}


ProcessDetailDialog::~ProcessDetailDialog()
{
    delete ui;
}