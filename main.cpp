#include <QApplication>
#include <QMetaType>
#include "controller/DashboardController.h"
#include "view/MainWindow.h"
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

int main(int argc, char *argv[]) {
    // Registra para uso em sinais entre threads
    qRegisterMetaType<std::vector<ProcessInfo>>("std::vector<ProcessInfo>");
    qRegisterMetaType<SystemInfo>("SystemInfo");

    QApplication app(argc, argv);

    MainWindow window(nullptr, nullptr);
    DashboardController controller(&window);
    window.setDashboardController(&controller); 
    window.show(); 

    return app.exec();
}