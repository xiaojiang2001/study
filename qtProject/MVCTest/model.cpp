#include "model.h"
#include <QTimer>

Model::Model(QObject *parent) : QObject(parent)
{
    Worker *worker = new Worker();
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Model::operate, worker, &Worker::doWork);
    connect(worker, &Worker::resultReady, this, &Model::dataProcessed);

    workerThread.start();
}

Model::~Model()
{
    workerThread.quit();
    workerThread.wait();
}

void Model::processData()
{
    emit operate();
}
