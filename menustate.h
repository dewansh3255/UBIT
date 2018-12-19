#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"

class MenuState : public State
{
public:
    MenuState(QMainWindow* window, QString page);
    ~MenuState();
    void resize(QResizeEvent* e);

private:
    QPixmap* background;
    QPalette* palette;
};

#endif // MENUSTATE_H
