#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), model(new Model(this))
{
    // 连接模型信号到控制器信号
    connect(model, &Model::dataProcessed, this, &Controller::on_dataProcessed);
}

void Controller::on_dataProcessed(QString result)
{
    qDebug() << "on_dataProcessed: " << result;
}

void Controller::on_button_clicked()
{
    qDebug() << "on_button_clicked";
    model->processData();
}
