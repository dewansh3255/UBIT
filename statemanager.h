#ifndef STATEMANAGER_H
#define STATEMANAGER_H

//QT Classes
#include <QObject>
#include <QLayout>

//Custom Classes
#include "loadstate.h"
#include "menustate.h"
#include "menubutton.h"
#include "textinput.h"

class StateManager : public QObject
{
    Q_OBJECT
public:
    explicit StateManager(QMainWindow* window = nullptr);
    ~StateManager();
    int randInt(int low, int high);
signals:


public slots:
    void loadScreen(State *state);
    void resize();    
    void nextMenu();

private:
    void loadScreen(MenuState *state);
    void loadScreen(LoadState *state);
    //Main Window
    QMainWindow* window;
    //Layout
    QLayout* mainLayout;
    State* currentState;
    //All screens
    QVector <State*> states;

    QTimer *timer;
};

#endif // STATEMANAGER_H
