#include "menustate.h"

MenuState::MenuState(QMainWindow *window, QString page):State(window)
{
    background = new QPixmap(":/res/img/"+page+".jpg");
    *background = background->scaled(window->size(), Qt::IgnoreAspectRatio);
    palette = new QPalette;
    palette->setBrush(QPalette::Background, *background);
    window->setPalette(*palette);
}

MenuState::~MenuState() {
    delete background;
    delete palette;
}

void MenuState::resize(QResizeEvent* e) {
    *background = background->scaled(e->size(), Qt::IgnoreAspectRatio);
    palette->setBrush(QPalette::Background, *background);
    window->setPalette(*palette);
}
