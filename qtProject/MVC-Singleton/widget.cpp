#include "widget.h"
#include "firstpageview.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // FirstPageView *firstPageView = new FirstPageView(this);
    setUi();
}

Widget::~Widget()
{

}

void Widget::setUi()
{
    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);


    // 设置widget样式
    QString borderStyle = "border: 2px solid blue; border-radius: 5px; padding: 5px;";

    //启动QWidget页面需要制定父对象this指针，不然会出现闪屏bug
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setStyleSheet(borderStyle);
    mainWidget->setLayout(mainLayout);
    mainWidget->setObjectName("mainWidget");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(mainWidget);
    this->setLayout(layout);


    initMenu();
    initStackWidget();
}

void Widget::initMenu()
{
    const QSize btnSize(120, 90);
    QPushButton *firstPageBtn = new QPushButton("第一页");
    firstPageBtn->setObjectName("firstPageBtn");
    firstPageBtn->setCheckable(true);
    firstPageBtn->setChecked(true);
    firstPageBtn->setFixedSize(btnSize);

    QPushButton *secondPageBtn = new QPushButton("第二页");
    secondPageBtn->setObjectName("secondPageBtn");
    secondPageBtn->setCheckable(true);
    secondPageBtn->setChecked(true);
    secondPageBtn->setFixedSize(btnSize);

    buttonGroup = new QButtonGroup();
    buttonGroup->setObjectName("buttonGroup");
    buttonGroup->addButton(firstPageBtn);
    buttonGroup->addButton(secondPageBtn);
    //只有一个按钮能被选中
    buttonGroup->setExclusive(true);
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroupSlot(int)));

    QHBoxLayout *menuLayout = new QHBoxLayout();
    menuLayout->setMargin(0);
    menuLayout->setSpacing(0);
    menuLayout->addWidget(firstPageBtn);
    menuLayout->addWidget(secondPageBtn);
    menuLayout->addStretch();

    mainLayout->addLayout(menuLayout);

}

void Widget::initStackWidget()
{
    //启动菜单栏界面
    FirstPageView *firstPageView = new FirstPageView(this);
    stackLayout = new QStackedLayout;
    stackLayout->addWidget(firstPageView);
    stackLayout->setCurrentIndex(0);
    mainLayout->addLayout(stackLayout);
}
