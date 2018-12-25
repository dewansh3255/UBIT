#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent, State* next, QString name) : QPushButton(name, parent)
{
    this->next = next;
}

void MenuButton::mousePressEvent(QMouseEvent *e)
{
    qDebug("Menu Button Pressed");
    emit screenChanged(next);
}

