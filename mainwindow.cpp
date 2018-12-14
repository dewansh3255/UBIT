//QT Files
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Custom
#include "screenmanager.h"


//ALWAYS PULL BEFORE STARTING

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initial Setup
    ui->setupUi(this);
    screenManager = new ScreenManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete screenManager;
}
