#include "screenmanager.h"


ScreenManager::ScreenManager(QWidget* window)
{
    this->window = window;
    mainLayout = new QGridLayout;
    //Generate a random loading time for loading screen
    quint32 time = QRandomGenerator::global()->generate();
    loadScreen(loadState, static_cast<int>(time));
}

ScreenManager::~ScreenManager()
{
    delete mainLayout;
}

void ScreenManager::loadScreen(LoadState *loadState, int time)
{
    loadState = new LoadState(window);

}
