#ifndef LOADSTATE_H
#define LOADSTATE_H

#include "state.h"

class LoadState : public State
{
public:
    LoadState(QMainWindow* window, QString shape);
    ~LoadState();
    void resize();
    void show();
    void hide();
};

#endif // LOADSTATE_H
