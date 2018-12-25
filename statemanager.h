#ifndef STATEMANAGER_H
#define STATEMANAGER_H

//QT Classes
#include <QObject>
#include <QLayout>

//Custom Classes
#include "loadstate.h"
#include "menustate.h"
#include "menubutton.h"

class StateManager : public QObject
{
    Q_OBJECT
public:
    explicit StateManager(QMainWindow* window = nullptr);
    ~StateManager();
signals:


public slots:
    void loadScreen(State *state);
    void resize();

private:
    //Main Window
    QMainWindow* window;
    //Layout
    QLayout* mainLayout;
    State* currentState;
    //All screens
    QVector <State*> states;

};

#endif // STATEMANAGER_H
