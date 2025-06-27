#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void updateLabel(QString text);

public slots:
    // 接收模型的信号槽函数
    void on_dataProcessed(QString result);
    // 接收视图按钮的信号槽函数
    void on_button_clicked();

private:
    Model *model;
};

#endif // CONTROLLER_H
