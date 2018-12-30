#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>

#include "states/state.h"

class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MenuButton(QWidget *parent = nullptr, State* next = nullptr, QString name="No Name");
signals:
    void screenChanged(State* next);
public slots:
    void mousePressEvent(QMouseEvent* e) override;

private:
    State *next;
};

#endif // MENUBUTTON_H
