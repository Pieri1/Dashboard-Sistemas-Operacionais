cmake_minimum_required(VERSION 3.16)
project(Dashboard)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Modulos necessários do Qt5
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

# Lista fontes e headers
set(SOURCES
    main.cpp
    view/MainWindow.cpp
    view/MainWindow.h
    view/MainWindow.ui
    view/ProcessDetailDialog.cpp
    view/ProcessDetailDialog.h
    view/ProcessDetailDialog.ui
    controller/DashboardController.cpp
    controller/DashboardController.h
    model/Worker.cpp
    model/ProcessInfo.cpp
    model/ProcessInfo.h
    model/SystemInfo.cpp
    model/SystemInfo.h
    model/ProcessManager.cpp
    model/ProcessManager.h
)

# Gera headers a partir dos .ui do designer
qt5_wrap_ui(UI_HEADERS
    MainWindow.ui
    ProcessDetailDialog.ui
)

# Cria o executável com todas fontes e headers de ui
add_executable(Dashboard ${SOURCES} ${UI_HEADERS})

# Define diretórios e caminhos
target_include_directories(Dashboard PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/Dashboard_autogen/include
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/model
    ${PROJECT_SOURCE_DIR}/view
    ${PROJECT_SOURCE_DIR}/controller
)

# liga executavel com recursos do Qt5
target_link_libraries(Dashboard Qt5::Widgets)
