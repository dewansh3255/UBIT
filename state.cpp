#include "state.h"

State::State(QMainWindow* window)
{
    this->window = window;
    this->layout = nullptr;
}

State::~State()
{
    for (int i = 0; i < widgets.size(); i++)
        delete widgets[i];
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

QWidget *State::getWidget(int index)
{
    if (index > widgets.size()-1) {
        qDebug()<<"Error: Widget not found!"<<endl;
        return nullptr;
    }
    return widgets[index];
}
