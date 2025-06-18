#ifndef FIRSTPAGEVIEW_H
#define FIRSTPAGEVIEW_H

#include <QWidget>
#include <QVBoxLayout>

class FirstPageView : public QWidget
{
    Q_OBJECT
public:
    explicit FirstPageView(QWidget *parent = nullptr);

private:
    void setUi();
    QVBoxLayout *mainLayout;

private slots:
    void showUiSlot();
    void showFinishedCountResultUISlot();

signals:

};

#endif // FIRSTPAGEVIEW_H
