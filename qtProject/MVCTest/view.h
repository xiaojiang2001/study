#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    QPushButton *getButton() const;
    QLabel *getLabel() const;

signals:

private:
    QPushButton *button;
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // VIEW_H
