#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer> // Adicione esta linha
#include "model/ProcessManager.h"

class Worker : public QObject {
    Q_OBJECT
public:
    explicit Worker(ProcessManager* manager, QObject* parent = nullptr);

signals:
    void processListReady(const std::vector<ProcessInfo>&);
    void systemInfoReady(const SystemInfo&);

public slots:
    void start();
    void updateData();

private:
    ProcessManager* manager;
    QTimer* timer;
};

#endif // WORKER_H