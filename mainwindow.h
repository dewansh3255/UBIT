#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT Files
#include <QMainWindow>

//Custom
#include "screenmanager.h"

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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ScreenManager *screenManager;
};

#endif // MAINWINDOW_H
