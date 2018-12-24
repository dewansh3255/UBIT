#include "menustate.h"

MenuState::MenuState(QMainWindow *window, QString page):State(window)
{
    url = ":/res/img/"+page+".jpg";
    background = new QPixmap(url);
    *background = background->scaled(window->size(), Qt::IgnoreAspectRatio);
    palette = new QPalette;
    palette->setBrush(QPalette::Background, *background);
    window->setPalette(*palette);
}

MenuState::~MenuState() {
    delete background;
    delete palette;
}

void MenuState::resize() {
    if (background)
        delete background;
    background = new QPixmap(url);
    *background = background->scaled(window->size(), Qt::IgnoreAspectRatio);
    palette->setBrush(QPalette::Background, *background);
    window->setPalette(*palette);
}
