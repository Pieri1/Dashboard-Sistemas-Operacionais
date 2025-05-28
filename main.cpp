#include <QApplication>
#include <QMetaType>
#include "controller/DashboardController.h"
#include "view/MainWindow.h"
#include "model/ProcessInfo.h"
#include "model/SystemInfo.h"

int main(int argc, char *argv[]) {
    qRegisterMetaType<std::vector<ProcessInfo>>("std::vector<ProcessInfo>");
    qRegisterMetaType<SystemInfo>("SystemInfo");
    QApplication app(argc, argv);

    MainWindow window(nullptr, nullptr); // Crie sem controller por enquanto
    DashboardController controller(&window);
    window.setDashboardController(&controller); // Defina o ponteiro depois
    window.show();

    controller.start();

    return app.exec();
}