#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

//QT Classes
#include <QLayout>

//Custom Classes
#include "loadstate.h"

class ScreenManager
{
public:
    ScreenManager(QWidget* window);
    ~ScreenManager();
    void loadScreen(LoadState* loadState, int time);

private:
    //Main Window
    QWidget* window;
    //Layout & States
    QLayout* mainLayout;
    LoadState* loadState;
};

#endif // SCREENMANAGER_H
