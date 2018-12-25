#include "menustate.h"

MenuState::MenuState(QMainWindow *window, QString page):State(window)
{
    background = nullptr;
    palette = nullptr;
    this->window = window;
    url = ":/res/img/"+page+".jpg";
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


void MenuState::show() {
    //Background
    background = new QPixmap(url);
    *background = background->scaled(window->size(), Qt::IgnoreAspectRatio);
    palette = new QPalette;
    palette->setBrush(QPalette::Background, *background);
    window->setPalette(*palette);
    //Widgets
    for (int i = 0; i < widgets.size(); i++) {
        this->layout->addWidget(widgets[i]);
        widgets[i]->show();
    }
}

void MenuState::hide() {
    qDebug("Hiding Menu");
    //Hiding Widgets
    for (int i = 0; i < widgets.size(); i++) {
        widgets[i]->hide();
        this->layout->removeWidget(widgets[i]);
    }
    //Hiding Background

}
