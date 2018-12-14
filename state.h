#ifndef STATE_H
#define STATE_H

//QT Classes
#include <QtWidgets>


class State
{
public:
    State(QWidget* window);
    ~State();
    //Widgets
    void addUiElements(QWidget* widget, QGroupBox *group);
protected:
    QWidget* window;
    //Background
    QMovie* gif;
    QLabel* gif_handler;
};

#endif // STATE_H
