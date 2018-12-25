#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT Files
#include <QMainWindow>

//Custom
#include "statemanager.h"

//Debug
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StateManager *stateManager;
};

#endif // MAINWINDOW_H
