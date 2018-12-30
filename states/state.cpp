#include "state.h"

State::State(QMainWindow* window) : QObject(window)
{
    this->window = window;
    this->layout = nullptr;
}

State::~State()
{
    for (int i = 0; i < widgets.size(); i++) {
        delete widgets[i];
        widgets[i] = nullptr;
    }
}

void State::addLayout(QLayout *layout)
{
    this->layout = layout;
    this->window->centralWidget()->setLayout(layout);
}

void State::addWidget(QWidget *widget)
{
    if (!layout) {
        qDebug()<<"Error: Layout not found!"<<endl;
        return;
    }
    this->widgets.push_back(widget);
    widget->hide();
}

void State::addWidget(TextInput *textInput)
{
    if (!layout) {
        qDebug()<<"Error: Layout not found!"<<endl;
        return;
    }
    this->widgets.push_back(textInput->textEdit);
    this->widgets.push_back(textInput->pushButton);
    textInput->pushButton->hide();
    textInput->textEdit->hide();
}


QWidget *State::getWidget(int index)
{
    if (index > widgets.size()-1) {
        qDebug()<<"Error: Widget not found!"<<endl;
        return nullptr;
    }
    return widgets[index];
}

//Processes
void State::levenshtein(QVector<QString> inputs)
{
    Levenshtein levenshtein(inputs, window);
    int i = 0;
    //Matrix
    while (i < widgets.size()) {
        if (dynamic_cast<QPlainTextEdit*>(widgets[i])) {
            dynamic_cast<QPlainTextEdit*>(widgets[i++])->setPlainText(levenshtein.matrix);
            break;
        }
        i++;
    }
    //Distance
    while (i < widgets.size()) {
        if (dynamic_cast<QPlainTextEdit*>(widgets[i])) {
            dynamic_cast<QPlainTextEdit*>(widgets[i])->setPlainText(levenshtein.distance);
            break;
        }
        i++;
    }

}
