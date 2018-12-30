#include "loadstate.h"

LoadState::LoadState(QMainWindow* window, QString shape):State(window)
{
    url = ":/res/img/"+shape+".gif";
    this->gif = new QMovie(url);
    this->gif_handler = new QLabel(window);
    this->window = window;
}

LoadState::~LoadState() {
    delete gif;
    delete gif_handler;
}

void LoadState::resize() {
    //Loading GIF background
    gif->setScaledSize(window->size());
    gif_handler->resize(window->width(), window->height());
}

void LoadState::show() {
    //Loading GIF only once
    this->layout->removeWidget(gif_handler);
    gif_handler->show();
    gif_handler->resize(window->width(), window->height());
    gif_handler->setMovie(gif);
    gif->setScaledSize(window->size());
    gif->start();
    //Showing Widgets
    for (int i = 0; i < widgets.size(); i++) {
        this->layout->addWidget(widgets[i]);
        widgets[i]->show();
    }
}

void LoadState::hide() {
    qDebug("Hiding Load Screen");
    //Stopping GIF background
    gif->stop();
    gif_handler->hide();
    layout->removeWidget(gif_handler);
    //Hiding Widgets
    for (int i = 0; i < widgets.size(); i++) {
        widgets[i]->hide();
        this->layout->removeWidget(widgets[i]);
    }
}
