#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QThread>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
    ~Model();

    void processData();

signals:
    void operate();
    void dataProcessed(const QString &result);

private:
    QThread workerThread;
};


class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork()
    {
        // Simulate long-running task
        QThread::sleep(2);
        emit resultReady("Data processed in background thread");
    }

signals:
    void resultReady(const QString &result);
};

#endif // MODEL_H
