#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QStackedLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void setUi();
    void initMenu();
    void initStackWidget();

    QVBoxLayout *mainLayout;
    QButtonGroup *buttonGroup;
    QStackedLayout *stackLayout;

};
#endif // WIDGET_H
