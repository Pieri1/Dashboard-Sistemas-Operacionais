#include "view/ProcessDetailDialog.h"
#include "ui_ProcessDetailDialog.h"

ProcessDetailDialog::ProcessDetailDialog(QWidget *parent) 
    : QDialog(parent), ui(new Ui::ProcessDetailDialog) {
    ui->setupUi(this);
}

ProcessDetailDialog::~ProcessDetailDialog()
{
    delete ui;
}