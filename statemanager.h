#ifndef STATEMANAGER_H
#define STATEMANAGER_H

//QT Classes
#include <QObject>
#include <QLayout>

//Custom Classes
#include "states/loadstate.h"
#include "states/menustate.h"
#include "custom_widgets/menubutton.h"
#include "custom_widgets/textinput.h"
#include "custom_widgets/processbutton.h"

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
    void removeScreen();
    QVector <QPlainTextEdit*> getInputs(State* state);
    void stylize(QWidget* widget);
    //Main Window
    QMainWindow* window;
    //Layout
    QLayout* mainLayout;
    State* currentState;
    int currentStateNumber;
    //All screens
    QVector <State*> states;

    //Timer
    QTimer* timer;
};

#endif // STATEMANAGER_H
