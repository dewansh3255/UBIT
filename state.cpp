#include "state.h"

State::State(QMainWindow* window)
{
    this->window = window;
    this->gif = nullptr;
    this->layout = nullptr;
}

State::~State()
{
    if (gif) {
        delete gif;
        delete gif_handler;
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
    this->layout->addWidget(widget);
}

QWidget *State::getWidget(int index)
{
    if (index > widgets.size()-1) {
        qDebug()<<"Error: Widget not found!"<<endl;
        return nullptr;
    }
    return widgets[index];
}

