#include "statemanager.h"

StateManager::StateManager(QMainWindow *window) : QObject(window)
{
    currentState = nullptr;
    timer = new QTimer(this);;
    this->window = window;
    mainLayout = new QFormLayout(window);

    //All Screens in Tree Form
    states.push_back(new LoadState(window, "blue_circle"));
    states.push_back(new MenuState(window, "home")); //Home
        states.push_back(new MenuState(window, "home")); //Utility Tools
            states.push_back(new MenuState(window, "home")); //Alignment Matching
                states.push_back(new MenuState(window, "processing")); //Local
                states.push_back(new MenuState(window, "processing")); //Global
            states.push_back(new MenuState(window, "home")); //Non Alignment Matching
                states.push_back(new MenuState(window, "processing")); //K-mer
                states.push_back(new MenuState(window, "processing")); //Hamming
                states.push_back(new MenuState(window, "processing")); //Lavenstein
            states.push_back(new MenuState(window, "neural_network")); //Neural Network
        states.push_back(new MenuState(window, "home")); //Help
        states.push_back(new MenuState(window, "home")); //Credits

    //Layouts for all screens
    for (int i = 0; i < states.size(); i++)
        states[i]->addLayout(mainLayout);

    //WIDGETS


    //Menu Tree Widgets
    int menu = 1;
    //Home
    states[menu]->addWidget(new QLabel("UBIT", window));
    states[menu]->addWidget(new MenuButton(window, states[menu+1], "Utility Tools"));
    states[menu]->addWidget(new MenuButton(window, states[menu+10], "Help"));
    states[menu]->addWidget(new MenuButton(window, states[menu+11], "Credits"));
    states[menu]->addWidget(new QPushButton("Exit", window));
    connect(states[menu]->widgets[4], SIGNAL(clicked()), window, SLOT(close())); //EXIT

    //Utility Tools
    int utility = menu+1;
    states[utility]->addWidget(new MenuButton(window, states[utility+1], "Allignment Matching"));
    states[utility]->addWidget(new MenuButton(window, states[utility+4], "Non-Allignment Matching"));
    states[utility]->addWidget(new MenuButton(window, states[utility+8], "Neural Network"));
    states[utility]->addWidget(new MenuButton(window, states[menu], "Back"));
    //Alignment
    int alignment = utility+1;
    states[alignment]->addWidget(new MenuButton(window, states[alignment+1], "Local Alignment")); //Local Alignment
        //Local
        int local = alignment+1;
        states[local]->addWidget(new QLabel("Local Input", window));
        states[local]->addWidget(new TextInput(window));
        states[local]->addWidget(new MenuButton(window, states[alignment], "Back"));
    states[alignment]->addWidget(new MenuButton(window, states[alignment+2], "Global Alignment")); //Global Alignment
        //Global
        int global = alignment+2;
        states[global]->addWidget(new QLabel("Global Input", window));

        states[global]->addWidget(new MenuButton(window, states[alignment], "Back"));
    states[alignment]->addWidget(new MenuButton(window, states[utility], "Back"));
    //Non Alignment
    int nalignment = utility+4;
    states[nalignment]->addWidget(new MenuButton(window, states[nalignment+1], "K-mer")); //K-mer
        //K-Mer
        int kmer = nalignment+1;
        states[kmer]->addWidget(new MenuButton(window, states[nalignment], "Back"));
    states[nalignment]->addWidget(new MenuButton(window, states[nalignment+2], "Hamming")); //Hamming
        //Hamming
        int hamming = nalignment+2;
        states[hamming]->addWidget(new MenuButton(window, states[nalignment], "Back"));
    states[nalignment]->addWidget(new MenuButton(window, states[nalignment+3], "Levenshtein")); //Lavenstein
        //Hamming
        int lavenstein = nalignment+3;
        states[lavenstein]->addWidget(new MenuButton(window, states[nalignment], "Back"));
    states[nalignment]->addWidget(new MenuButton(window, states[utility], "Back"));
    //Neural Network
    int neural = utility+8;
    states[neural]->addWidget(new MenuButton(window, states[utility], "Back"));

    //Help
    int help = menu+10;
    states[help]->addWidget(new MenuButton(window, states[menu], "Back"));

    //Credits
    int credits = menu+11;
    states[credits]->addWidget(new MenuButton(window, states[menu], "Back"));

    //Load the first screen
    loadScreen(states[0]);

    //For all buttons
    for (int i = 0; i < states.size(); i++)
        for (int j = 0; j < states[i]->widgets.size(); j++)
            if (dynamic_cast<MenuButton*>(states[i]->widgets[j]))
                QObject::connect(states[i]->widgets[j], SIGNAL(screenChanged(State*)), this, SLOT(loadScreen(State*)));
}


StateManager::~StateManager()
{
    for (int i = 0; i < states.size(); i++)
        delete states[i];
    if (mainLayout)
        delete mainLayout;
    delete timer;
}

void StateManager::resize()
{
    if(currentState)
        currentState->resize();
}

void StateManager::loadScreen(State *state) {
    if (dynamic_cast<MenuState*>(state))
        loadScreen(dynamic_cast<MenuState*>(state));
    else if (dynamic_cast<LoadState*>(state))
        loadScreen(dynamic_cast<LoadState*>(state));
}

void StateManager::loadScreen(MenuState *state)
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

void StateManager::loadScreen(LoadState *state)
{
    if (currentState) {
        qDebug("Hiding Old Screen");
        currentState->hide();
        qDebug("Old Screen Hidden");
    }
    qDebug()<<"Showing new menu with "<<state->widgets.size()<<" widgets.";
    currentState = state;
    state->show();
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
    connect(timer, SIGNAL(timeout()), this, SLOT(nextMenu()));
    timer->setSingleShot(true); // if you only want it to fire once
    timer->start(randInt(1000, 2000));
}


int StateManager::randInt(int low, int high)
{
    // Random number between low and high
    int num = qrand() % ((high + 1) - low) + low;
    return num;
}

void StateManager::nextMenu()
{
    loadScreen(states[1]);
}
