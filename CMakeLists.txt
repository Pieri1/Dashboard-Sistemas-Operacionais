cmake_minimum_required(VERSION 3.16)
project(Dashboard)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)


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
    model/ProcessInfo.cpp
    model/ProcessInfo.h
    model/SystemInfo.cpp
    model/SystemInfo.h
    model/ProcessManager.cpp
    model/ProcessManager.h
)

qt5_wrap_ui(UI_HEADERS
    MainWindow.ui
    ProcessDetailDialog.ui
)

add_executable(Dashboard ${SOURCES} ${UI_HEADERS})

target_include_directories(Dashboard PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/Dashboard_autogen/include
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/model
    ${PROJECT_SOURCE_DIR}/view
    ${PROJECT_SOURCE_DIR}/controller
)

target_link_libraries(Dashboard Qt5::Widgets)
