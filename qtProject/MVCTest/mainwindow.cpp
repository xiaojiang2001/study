#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include "view.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    controller(new Controller(this)),
    view(new View(this))
{
    // ui->setupUi(this);
    setCentralWidget(view);

    // 连接视图信号到控制器 启动业务逻辑功能信号
    connect(view->getButton(), &QPushButton::clicked, controller, &Controller::on_button_clicked);
    // 连接控制器信号到视图
    connect(controller, &Controller::updateLabel, view->getLabel(),  &QLabel::setText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

