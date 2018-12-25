#include "statemanager.h"

StateManager::StateManager(QMainWindow *window) : QObject(window)
{
    currentState = nullptr;
    this->window = window;
    mainLayout = new QGridLayout;
    //Generate a random loading time for loading screen
    //quint32 time = QRandomGenerator::global()->generate();

    //All Screens
    states.push_back(new MenuState(window, "home"));
    states.push_back(new MenuState(window, "processing"));

    for (int i = 0; i < states.size(); i++)
        states[i]->addLayout(mainLayout);

    //First Screen Widgets
    states[0]->addWidget(new MenuButton(window, states[1], "Go to 1st"));

    states[1]->addWidget(new MenuButton(window, states[0], "Go back"));
    states[1]->addWidget(new MenuButton(window, states[0], "Go back"));
    states[1]->addWidget(new MenuButton(window, states[0], "Go back"));


    loadScreen(states[0]);


    //For all buttons
    for (int i = 0; i < states.size(); i++)
        for (int j = 0; j < states[i]->widgets.size(); j++)
            if (dynamic_cast<QPushButton*>(states[i]->widgets[i]))
                QObject::connect(states[i]->widgets[i], SIGNAL(screenChanged(State*)), this, SLOT(loadScreen(State*)));
}


StateManager::~StateManager()
{
    for (int i = 0; i < states.size(); i++)
        delete states[i];
    if (mainLayout)
        delete mainLayout;
}

void StateManager::resize()
{
//    if(currentState)
//        currentState->resize();
}

void StateManager::loadScreen(State *state)
{
    if (currentState) {
        qDebug("Hiding Old Screen");
        currentState->hide();
        qDebug("Old Screen Hidden");
    }
    qDebug()<<"Showing new menu with "<<state->widgets.size()<<" widgets.";
    currentState = state;
    state->show();
}
