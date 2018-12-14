#include "screenmanager.h"

ScreenManager::ScreenManager()
{
    gif = nullptr;
    mainLayout = new QGridLayout;
}

ScreenManager::~ScreenManager()
{
    if (gif) {
        delete gif;
        delete gif_label;
    }
    delete mainLayout;
}

void ScreenManager::setBackground(QString path, QWidget* window)
{
    //For gif file
    if (path[path.size()-1] == "f") {
        if (this->gif == nullptr) {
            this->gif = new QMovie(path);
            this->gif_label = new QLabel(window);
            gif_label->resize(window->width(), window->height());
        }
        else
            this->gif->setFileName(path);
        gif_label->setMovie(gif);
        gif->start();
    } else {
        //If background is already a gif
        if (this->gif) {
            delete gif;
            delete gif_label;
            gif = nullptr;
        }
        //Code for image background
        QPixmap background(path);
        background = background.scaled(window->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, background);
        window->setPalette(palette);
    }
}

