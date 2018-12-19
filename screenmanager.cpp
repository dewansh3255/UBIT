#include "screenmanager.h"


ScreenManager::ScreenManager(QMainWindow* window)
{
    this->window = window;
    mainLayout = new QGridLayout;
    //Generate a random loading time for loading screen
    quint32 time = QRandomGenerator::global()->generate();
    loadScreen(currentState, static_cast<int>(time));
}

ScreenManager::~ScreenManager()
{
    delete mainLayout;
}

void ScreenManager::resize(QResizeEvent *e)
{
    currentState->resize(e);
}

void ScreenManager::loadScreen(State *state, int time)
{
    state = new MenuState(window,"home");
    state->addLayout(mainLayout);
    QPushButton* button = new QPushButton(window);
    state->addWidget(button);
    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}
