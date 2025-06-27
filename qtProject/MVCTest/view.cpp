#include "view.h"

View::View(QWidget *parent) : QWidget(parent)
{
    button = new QPushButton("Click me", this);
    label = new QLabel("Initial text", this);
    layout = new QVBoxLayout(this);

    layout->addWidget(button);
    layout->addWidget(label);

    setLayout(layout);
}

QPushButton *View::getButton() const
{
    return button;
}

QLabel *View::getLabel() const
{
    return label;
}
