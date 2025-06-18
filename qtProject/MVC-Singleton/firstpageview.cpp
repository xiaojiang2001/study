#include "firstpageview.h"
#include "QPushButton"
#include <QDebug>
#include <QMessageBox>
#include "singleton.h"
#include "firstpagecontroller.h"

FirstPageView::FirstPageView(QWidget *parent) : QWidget(parent)
{
    setUi();
}

void FirstPageView::setUi()
{
    QPushButton *firstPage = new QPushButton(tr("我是第一页的页面：点击我实现2+3计算功能(业务逻辑功能)"));
    connect(firstPage, SIGNAL(clicked(bool)), this, SLOT(showUiSlot()));
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(firstPage);
    mainLayout->addStretch();

    // connect(&Singleton<FirstPageController>::getInstance(), SIGNAL(showFinishedCountUiSignal()), this, SLOT(showFinishedCountResultUISlot()));
}


void FirstPageView::showUiSlot()
{
    // emit Singleton<FirstPageController>::getInstance().startedCountSignal();
}

void FirstPageView::showFinishedCountResultUISlot()
{
    qDebug()<<tr("显示计算后界面！！！");
        QMessageBox::warning(this,QStringLiteral("结果界面"),QStringLiteral("显示计算后界面！！！"),QMessageBox::Yes,QMessageBox::No);
}

