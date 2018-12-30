#ifndef STATE_H
#define STATE_H

//QT Classes
#include <QtWidgets>
#include <textinput.h>

class State : public QObject
{
    Q_OBJECT
public:
    State(QMainWindow* window);
    virtual ~State();
    virtual void resize() = 0; //REIMPLEMENT THIS USING QOBJECT
    virtual void show() = 0;
    virtual void hide() = 0;
    //Widgets
    void addLayout(QLayout* layout);
    void addWidget(QWidget* widget);
    void addWidget(TextInput* textInput);
    QWidget* getWidget(int index);

    //Processing Functions
    void levenshtein(QVector <QString> inputs);

    friend class StateManager;

protected:
    QMainWindow* window;
    //Background
    QMovie* gif;
    QLabel* gif_handler;
    QString url;
    //UI
    QLayout* layout;
    QVector <QWidget*> widgets;
};

#endif // STATE_H
