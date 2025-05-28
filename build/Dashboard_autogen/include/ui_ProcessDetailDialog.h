/********************************************************************************
** Form generated from reading UI file 'ProcessDetailDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSDETAILDIALOG_H
#define UI_PROCESSDETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProcessDetailDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblPId;
    QLabel *lblName;
    QLabel *lblUser;
    QLabel *lblState;
    QLabel *lblThreads;
    QLabel *lblParent;
    QLabel *lblCpuTime;
    QLabel *lblMemVirtual;
    QLabel *lblMemRam;
    QLabel *lblPriority;
    QLabel *lblFiles;
    QLabel *lblPages;
    QPushButton *btnClose;

    void setupUi(QDialog *ProcessDetailDialog)
    {
        if (ProcessDetailDialog->objectName().isEmpty())
            ProcessDetailDialog->setObjectName(QString::fromUtf8("ProcessDetailDialog"));
        ProcessDetailDialog->resize(260, 433);
        verticalLayout = new QVBoxLayout(ProcessDetailDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ProcessDetailDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblPId = new QLabel(groupBox);
        lblPId->setObjectName(QString::fromUtf8("lblPId"));

        verticalLayout_2->addWidget(lblPId);

        lblName = new QLabel(groupBox);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        verticalLayout_2->addWidget(lblName);

        lblUser = new QLabel(groupBox);
        lblUser->setObjectName(QString::fromUtf8("lblUser"));

        verticalLayout_2->addWidget(lblUser);

        lblState = new QLabel(groupBox);
        lblState->setObjectName(QString::fromUtf8("lblState"));

        verticalLayout_2->addWidget(lblState);

        lblThreads = new QLabel(groupBox);
        lblThreads->setObjectName(QString::fromUtf8("lblThreads"));

        verticalLayout_2->addWidget(lblThreads);

        lblParent = new QLabel(groupBox);
        lblParent->setObjectName(QString::fromUtf8("lblParent"));

        verticalLayout_2->addWidget(lblParent);

        lblCpuTime = new QLabel(groupBox);
        lblCpuTime->setObjectName(QString::fromUtf8("lblCpuTime"));

        verticalLayout_2->addWidget(lblCpuTime);

        lblMemVirtual = new QLabel(groupBox);
        lblMemVirtual->setObjectName(QString::fromUtf8("lblMemVirtual"));

        verticalLayout_2->addWidget(lblMemVirtual);

        lblMemRam = new QLabel(groupBox);
        lblMemRam->setObjectName(QString::fromUtf8("lblMemRam"));

        verticalLayout_2->addWidget(lblMemRam);

        lblPriority = new QLabel(groupBox);
        lblPriority->setObjectName(QString::fromUtf8("lblPriority"));

        verticalLayout_2->addWidget(lblPriority);

        lblFiles = new QLabel(groupBox);
        lblFiles->setObjectName(QString::fromUtf8("lblFiles"));

        verticalLayout_2->addWidget(lblFiles);

        lblPages = new QLabel(groupBox);
        lblPages->setObjectName(QString::fromUtf8("lblPages"));

        verticalLayout_2->addWidget(lblPages);


        verticalLayout->addWidget(groupBox);

        btnClose = new QPushButton(ProcessDetailDialog);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        verticalLayout->addWidget(btnClose);


        retranslateUi(ProcessDetailDialog);

        QMetaObject::connectSlotsByName(ProcessDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessDetailDialog)
    {
        ProcessDetailDialog->setWindowTitle(QCoreApplication::translate("ProcessDetailDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ProcessDetailDialog", "GroupBox", nullptr));
        lblPId->setText(QCoreApplication::translate("ProcessDetailDialog", "PID:", nullptr));
        lblName->setText(QCoreApplication::translate("ProcessDetailDialog", "Nome:", nullptr));
        lblUser->setText(QCoreApplication::translate("ProcessDetailDialog", "Usuario:", nullptr));
        lblState->setText(QCoreApplication::translate("ProcessDetailDialog", "Estado:", nullptr));
        lblThreads->setText(QCoreApplication::translate("ProcessDetailDialog", "Threads:", nullptr));
        lblParent->setText(QCoreApplication::translate("ProcessDetailDialog", "PPID:", nullptr));
        lblCpuTime->setText(QCoreApplication::translate("ProcessDetailDialog", "Tempo de CPU:", nullptr));
        lblMemVirtual->setText(QCoreApplication::translate("ProcessDetailDialog", "Memoria Virtual:", nullptr));
        lblMemRam->setText(QCoreApplication::translate("ProcessDetailDialog", "Memoria RAM:", nullptr));
        lblPriority->setText(QCoreApplication::translate("ProcessDetailDialog", "Prioridade:", nullptr));
        lblFiles->setText(QCoreApplication::translate("ProcessDetailDialog", "Arquivos abertos:", nullptr));
        lblPages->setText(QCoreApplication::translate("ProcessDetailDialog", "Paginas:", nullptr));
        btnClose->setText(QCoreApplication::translate("ProcessDetailDialog", "Fechar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessDetailDialog: public Ui_ProcessDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSDETAILDIALOG_H
