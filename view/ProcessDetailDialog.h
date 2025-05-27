#pragma once
#include <QDialog>

namespace Ui {
class ProcessDetailDialog;
}

class ProcessDetailDialog : public QDialog {
    Q_OBJECT
public:
    explicit ProcessDetailDialog(QWidget *parent = nullptr);
    ~ProcessDetailDialog();
    
private:
    Ui::ProcessDetailDialog *ui;
};