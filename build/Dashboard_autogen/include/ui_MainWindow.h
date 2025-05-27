/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lblCpuUse;
    QLabel *lblCpuIdle;
    QLabel *lblMemUse;
    QLabel *lblMemFree;
    QLabel *lblTotalProc;
    QTableWidget *tblProcess;
    QLabel *lblUpdate;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 435);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblCpuUse = new QLabel(groupBox);
        lblCpuUse->setObjectName(QString::fromUtf8("lblCpuUse"));

        horizontalLayout->addWidget(lblCpuUse);

        lblCpuIdle = new QLabel(groupBox);
        lblCpuIdle->setObjectName(QString::fromUtf8("lblCpuIdle"));

        horizontalLayout->addWidget(lblCpuIdle);

        lblMemUse = new QLabel(groupBox);
        lblMemUse->setObjectName(QString::fromUtf8("lblMemUse"));

        horizontalLayout->addWidget(lblMemUse);

        lblMemFree = new QLabel(groupBox);
        lblMemFree->setObjectName(QString::fromUtf8("lblMemFree"));

        horizontalLayout->addWidget(lblMemFree);

        lblTotalProc = new QLabel(groupBox);
        lblTotalProc->setObjectName(QString::fromUtf8("lblTotalProc"));

        horizontalLayout->addWidget(lblTotalProc);


        verticalLayout->addWidget(groupBox);

        tblProcess = new QTableWidget(centralwidget);
        if (tblProcess->columnCount() < 7)
            tblProcess->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblProcess->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblProcess->setObjectName(QString::fromUtf8("tblProcess"));
        tblProcess->setColumnCount(7);

        verticalLayout->addWidget(tblProcess);

        lblUpdate = new QLabel(centralwidget);
        lblUpdate->setObjectName(QString::fromUtf8("lblUpdate"));

        verticalLayout->addWidget(lblUpdate);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 901, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        lblCpuUse->setText(QCoreApplication::translate("MainWindow", "Uso de CPU: ?%", nullptr));
        lblCpuIdle->setText(QCoreApplication::translate("MainWindow", "CPU Ociosa: ?%", nullptr));
        lblMemUse->setText(QCoreApplication::translate("MainWindow", "Uso de Ram: ?%", nullptr));
        lblMemFree->setText(QCoreApplication::translate("MainWindow", "Ram Livre: ?%", nullptr));
        lblTotalProc->setText(QCoreApplication::translate("MainWindow", "Processos: ?", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblProcess->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblProcess->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblProcess->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Usu\303\241rio", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblProcess->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "CPU%", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblProcess->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Mem\303\263ria (MB)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblProcess->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Threads", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblProcess->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Estado", nullptr));
        lblUpdate->setText(QCoreApplication::translate("MainWindow", "\303\232ltima atualiza\303\247\303\243o: 00:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
