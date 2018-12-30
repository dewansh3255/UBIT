#include "statemanager.h"

StateManager::StateManager(QMainWindow *window) : QObject(window)
{
    timer = nullptr;
    currentState = nullptr;
    currentStateNumber = 0;
    this->window = window;
    mainLayout = new QFormLayout;

    //All Screens in Tree Form
    states.push_back(new LoadState(window, "blue_circle"));
    states.push_back(new MenuState(window, "home")); //Home
        states.push_back(new MenuState(window, "home")); //Utility Tools
            states.push_back(new MenuState(window, "home")); //Alignment Matching
                states.push_back(new MenuState(window, "processing")); //Local
                    states.push_back(new LoadState(window, "multi_dna"));
                    states.push_back(new MenuState(window, "result"));
                states.push_back(new MenuState(window, "processing")); //Global
                    states.push_back(new LoadState(window, "multi_dna"));
                    states.push_back(new MenuState(window, "result"));
            states.push_back(new MenuState(window, "home")); //Non Alignment Matching
                states.push_back(new MenuState(window, "processing")); //K-mer
                    states.push_back(new LoadState(window, "multi_dna"));
                    states.push_back(new MenuState(window, "result"));
                states.push_back(new MenuState(window, "processing")); //Hamming
                    states.push_back(new LoadState(window, "multi_dna"));
                    states.push_back(new MenuState(window, "result"));
                states.push_back(new MenuState(window, "processing")); //Lavenstein
                    states.push_back(new LoadState(window, "multi_dna"));
                    states.push_back(new MenuState(window, "result"));
            states.push_back(new MenuState(window, "neural_network")); //Neural Network
                states.push_back(new LoadState(window, "multi_dna"));
                states.push_back(new MenuState(window, "result"));
        states.push_back(new MenuState(window, "home")); //Help
        states.push_back(new MenuState(window, "home")); //Credits

    //Layouts for all screens
    for (int i = 0; i < states.size(); i++)
        states[i]->addLayout(mainLayout);


    //Menu Tree Widgets
    int menu = 1,
        utility = menu+1,
            align = utility+1,
                local = align+1,
                global = align+4,
            nalign = utility+8,
                kmer = nalign+1,
                hamming = nalign+4,
                levenshtein = nalign+7,
            nn = utility+18,
        help = menu+21,
        credits = menu+22;
    //Home
    states[menu]->addWidget(new QLabel("UBIT", window));
    states[menu]->addWidget(new MenuButton(window, states[utility], "Utility Tools"));
    states[menu]->addWidget(new MenuButton(window, states[help], "Help"));
    states[menu]->addWidget(new MenuButton(window, states[credits], "Credits"));
    states[menu]->addWidget(new QPushButton("Exit", window));
    connect(states[menu]->widgets[4], SIGNAL(clicked()), window, SLOT(close())); //EXIT

    //Utility Tools
    states[utility]->addWidget(new MenuButton(window, states[align], "Allignment Matching"));
    states[utility]->addWidget(new MenuButton(window, states[nalign], "Non-Allignment Matching"));
    states[utility]->addWidget(new MenuButton(window, states[nn], "Neural Network"));
    states[utility]->addWidget(new MenuButton(window, states[menu], "Back"));
    //Alignment
    states[align]->addWidget(new MenuButton(window, states[local], "Local Alignment")); //Local Alignment
        //Local
        states[local]->addWidget(new QLabel("Local Input", window));
        states[local]->addWidget(new TextInput(window));
        states[local]->addWidget(new TextInput(window));
        states[local]->addWidget(new ProcessButton(getInputs(states[local])));
            //Local Result
            states[local+2]->addWidget(new QLabel("Local Matrix", window));
            states[local+2]->addWidget(new QPlainTextEdit(window));
            states[local+2]->addWidget(new QLabel("Best Comparison", window));
            states[local+2]->addWidget(new QPlainTextEdit(window));
            states[local+2]->addWidget(new MenuButton(window, states[local], "Back"));
        states[local]->addWidget(new MenuButton(window, states[align], "Back"));
    states[align]->addWidget(new MenuButton(window, states[global], "Global Alignment")); //Global Alignment
        //Global
        states[global]->addWidget(new QLabel("Global Input", window));
        states[global]->addWidget(new TextInput(window));
        states[global]->addWidget(new TextInput(window));
        states[global]->addWidget(new ProcessButton(getInputs(states[global])));
            //Global Result
            states[global+2]->addWidget(new QLabel("Global Matrix", window));
            states[global+2]->addWidget(new QPlainTextEdit(window));
            states[global+2]->addWidget(new QLabel("Best Comparison", window));
            states[global+2]->addWidget(new QPlainTextEdit(window));
            states[global+2]->addWidget(new MenuButton(window, states[global], "Back"));
        states[global]->addWidget(new MenuButton(window, states[align], "Back"));
    states[align]->addWidget(new MenuButton(window, states[utility], "Back"));
    //Non Alignment
    states[nalign]->addWidget(new MenuButton(window, states[kmer], "K-mer")); //K-mer
        //K-Mer
        states[kmer]->addWidget(new QLabel("Input K-Mer String", window));
        states[kmer]->addWidget(new TextInput(window));
        states[kmer]->addWidget(new ProcessButton(getInputs(states[kmer]), window));
            //K-mer Result
            states[kmer+2]->addWidget(new QLabel("K-Mer Substrings", window));
            states[kmer+2]->addWidget(new QPlainTextEdit(window));
            states[kmer+2]->addWidget(new MenuButton(window, states[kmer], "Back"));
        states[kmer]->addWidget(new MenuButton(window, states[nalign], "Back"));
    states[nalign]->addWidget(new MenuButton(window, states[hamming], "Hamming")); //Hamming
        //Hamming
        states[hamming]->addWidget(new QLabel("Hamming Input", window));
        states[hamming]->addWidget(new TextInput(window));
        states[hamming]->addWidget(new TextInput(window));
        states[hamming]->addWidget(new ProcessButton(getInputs(states[hamming])));
            //Hamming Result
            states[hamming+2]->addWidget(new QLabel("Hamming Distance", window));
            states[hamming+2]->addWidget(new QPlainTextEdit(window));
            states[hamming+2]->addWidget(new MenuButton(window, states[hamming], "Back"));
        states[hamming]->addWidget(new MenuButton(window, states[nalign], "Back"));
    states[nalign]->addWidget(new MenuButton(window, states[levenshtein], "Levenshtein")); //Lavenstein
        //Levenshtein
        states[levenshtein]->addWidget(new QLabel("Levenshtein Input", window));
        states[levenshtein]->addWidget(new TextInput(window)); //2 WIDGETS
        states[levenshtein]->addWidget(new TextInput(window));
        states[levenshtein]->addWidget(new ProcessButton(getInputs(states[levenshtein])));
        connect(dynamic_cast<ProcessButton*>(states[levenshtein]->getWidget(5)), SIGNAL(sendText(QVector <QString>)), states[levenshtein+2], SLOT(levenshtein(QVector <QString>)));
            //Levenshtein Result
            states[levenshtein+2]->addWidget(new QLabel("Levenshtein Matrix", window));
            states[levenshtein+2]->addWidget(new QPlainTextEdit(window));
            states[levenshtein+2]->addWidget(new QLabel("Levenshtein Distance", window));
            states[levenshtein+2]->addWidget(new QPlainTextEdit(window));
            states[levenshtein+2]->addWidget(new MenuButton(window, states[levenshtein], "Back"));
        states[levenshtein]->addWidget(new MenuButton(window, states[nalign], "Back"));
    states[nalign]->addWidget(new MenuButton(window, states[utility], "Back"));
    //Neural Network
    states[nn]->addWidget(new QLabel("Neural Network Input", window));
        //Neural Network Result
        states[nn+2]->addWidget(new QLabel("Neural Network Output", window));
    states[nn]->addWidget(new MenuButton(window, states[utility], "Back"));

    //Help
    states[help]->addWidget(new MenuButton(window, states[menu], "Back"));

    //Credits
    states[credits]->addWidget(new MenuButton(window, states[menu], "Back"));

    //Load the first screen
    loadScreen(states[1]);

    //For every widget in the program, connect all menus and stylize all of them
    for (int i = 0; i < states.size(); i++)
        for (int j = 0; j < states[i]->widgets.size(); j++) {
            if (dynamic_cast<MenuButton*>(states[i]->widgets[j]))
                QObject::connect(states[i]->widgets[j], SIGNAL(screenChanged(State*)), this, SLOT(loadScreen(State*)));
            if (dynamic_cast<ProcessButton*>(states[i]->widgets[j]))
                QObject::connect(states[i]->widgets[j], SIGNAL(sendText(QVector <QString>)), this, SLOT(nextMenu())); //Load Screen
            stylize(states[i]->widgets[j]);
        }
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
    if (currentState) {
        qDebug("Hiding Old Screen");
        currentState->hide();
        qDebug("Old Screen Hidden");
    }
    qDebug()<<"Showing new menu with "<<state->widgets.size()<<" widgets.";
    currentState = state;
    state->show();
    //Update Screen Number
    if (states[currentStateNumber] != currentState)
        for (int i = 0; i < states.size(); i++)
            if (states[i] == currentState) {
                currentStateNumber = i;
                break;
            }

    qDebug()<<"Current Screen Number: "<<currentStateNumber;
    //If loading screen, set a time
    if (dynamic_cast<LoadState*>(state))
        removeScreen();
}

void StateManager::removeScreen()
{
    if (timer)
        delete timer;
    timer = new QTimer(window);
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
    connect(timer, SIGNAL(timeout()), this, SLOT(nextMenu()));
    timer->setSingleShot(true); //Fire only once
    if (currentStateNumber == 0)
        timer->start(randInt(5000, 6000));
    else
        timer->start(randInt(1000, 2500));
    connect(this, &StateManager::destroyed, timer , &QTimer::deleteLater); // delete the member when the class is going to be destroyed
}

void StateManager::nextMenu()
{
    loadScreen(states[++currentStateNumber]);
}

QVector<QPlainTextEdit *> StateManager::getInputs(State *state)
{
    QVector <QPlainTextEdit *> inputs;
    for (int i = 0; i < state->widgets.size(); i++)
        if (dynamic_cast<QPlainTextEdit*>(state->widgets[i]))
            inputs.push_back(dynamic_cast<QPlainTextEdit*>(state->widgets[i]));
    return inputs;
}

void StateManager::stylize(QWidget *widget)
{
    //For push buttons
    if (dynamic_cast<QPushButton*>(widget)) {
        QPushButton* button = dynamic_cast<QPushButton*>(widget);
        button->setStyleSheet("background-color: rgba(50,50,50,0.7);"
                              "color: white;"
                              "padding: 10px 0;"
                              "font-size: 12px;"
                              "border-radius: 8px;");
    } else if (dynamic_cast<QLabel*>(widget)) { //For Labels
        QLabel* heading = dynamic_cast<QLabel*>(widget);
        heading->setStyleSheet("color: white;"
                               "font-size: 18px;");
        heading->setAlignment(Qt::AlignCenter);
    }
    //widget->setMaximumWidth(350);
}

int StateManager::randInt(int low, int high)
{
    // Random number between low and high
    int num = qrand() % ((high + 1) - low) + low;
    return num;
}
