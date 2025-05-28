#include "model/Worker.h"
#include <QTimer>
#include <QThread>

Worker::Worker(ProcessManager* manager, QObject* parent)
    : QObject(parent), manager(manager), timer(nullptr) {}

void Worker::start() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Worker::updateData);
    timer->start(5000);
    updateData();
}

void Worker::updateData() {
    auto list = manager->getProcessList();
    emit processListReady(list);
    auto sys = manager->getSystemInfo();
    emit systemInfoReady(sys);
}