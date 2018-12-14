#include "loadstate.h"

LoadState::LoadState(QWidget* window):State(window)
{
    QString background_path = ":/res/img/blue_circle.gif";
    //Loading GIF background
    if (this->gif == nullptr) {
        this->gif = new QMovie(background_path);
        this->gif_handler = new QLabel(window);
        gif_handler->resize(window->width(), window->height());
    }
    else
        this->gif->setFileName(background_path);
    gif_handler->setMovie(gif);
    gif->start();
}
