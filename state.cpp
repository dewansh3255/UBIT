#include "state.h"

State::State(QWidget* window)
{
    this->window = window;
    gif = nullptr;
}

State::~State()
{
    if (gif) {
        delete gif;
        delete gif_handler;
    }
}
