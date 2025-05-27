#include <QApplication>
#include "view/MainWindow.h"
#include "controller/DashboardController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    DashboardController controller(&window);
    controller.start();

    return app.exec();
}