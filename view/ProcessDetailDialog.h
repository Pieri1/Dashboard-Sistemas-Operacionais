#ifndef PROCESSDETAILDIALOG_H
#define PROCESSDETAILDIALOG_H

#include <QDialog>
#include "model/ProcessManager.h"

namespace Ui {
class ProcessDetailDialog;
}

class ProcessDetailDialog : public QDialog {
    Q_OBJECT

public:
    explicit ProcessDetailDialog(QWidget *parent = nullptr);
    ~ProcessDetailDialog();

    void setPid(int pid);
    void setProcessDetails(const ProcessDetails& d);

private:
    Ui::ProcessDetailDialog *ui;
};

#endif