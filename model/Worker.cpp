#include "model/Worker.h"
#include <QTimer>
#include <QThread>

// Worker é responsavel por coletar os dados periodicamente via ProcessManager dividindo a carga de trabalho
Worker::Worker(ProcessManager* manager, QObject* parent)
    : QObject(parent), manager(manager), timer(nullptr) {}

// Cria e inicia um QTimer para atualizar os dados periodicamente (a cada 1 segundo)
void Worker::start() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Worker::updateData);
    timer->start(1000);
    updateData(); 
}

// Coleta os dados do sistema e emite sinais com os dados
void Worker::updateData() {
    auto list = manager->getProcessList();  
    emit processListReady(list);           
    auto sys = manager->getSystemInfo();   
    emit systemInfoReady(sys);      
}