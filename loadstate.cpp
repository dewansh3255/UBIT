#include "loadstate.h"

LoadState::LoadState(QMainWindow* window, QString shape):State(window)
{
    url = ":/res/img/"+shape+".gif";
    //Loading GIF background
    if (this->gif == nullptr) {
        this->gif = new QMovie(url);
        this->gif_handler = new QLabel(window);
        gif_handler->resize(window->width(), window->height());
    }
    else
        this->gif->setFileName(url);
    gif_handler->setMovie(gif);
    gif->setScaledSize(window->size());
    gif->start();
}


LoadState::~LoadState() {
    //Deleting gif or gif_handler is causing
    //the program to crash for some unknown
    //reason. I sit here in confusion.
}

void LoadState::resize() {
    //Loading GIF background
    gif->setScaledSize(window->size());
    gif_handler->resize(window->width(), window->height());
}
