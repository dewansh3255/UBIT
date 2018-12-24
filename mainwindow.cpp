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
    resize(600, 600);
    screenManager = new ScreenManager(this);
}



MainWindow::~MainWindow()
{
    delete ui;
    delete screenManager;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (screenManager)
        screenManager->resize();
    QWidget::resizeEvent(event);
}
