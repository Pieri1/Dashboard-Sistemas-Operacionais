#include <QApplication>
#include "controller/DashboardController.h"
#include "view/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window(nullptr, nullptr); // Crie sem controller por enquanto
    DashboardController controller(&window);
    window.setDashboardController(&controller); // Defina o ponteiro depois
    window.show();

    controller.start();

    return app.exec();
}