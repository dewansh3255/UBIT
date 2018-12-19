#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

//QT Classes
#include <QLayout>

//Custom Classes
#include "loadstate.h"
#include "menustate.h"

class ScreenManager
{
public:
    ScreenManager(QMainWindow* window);
    ~ScreenManager();
    void resize(QResizeEvent* e);
    void loadScreen(State* state, int time);

private:
    //Main Window
    QMainWindow* window;
    //Layout & States
    QLayout* mainLayout;
    State* currentState;
};

#endif // SCREENMANAGER_H
