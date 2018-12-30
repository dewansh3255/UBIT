//QT Files
#include "mainwindow.h"
#include "ui_mainwindow.h"



//ALWAYS PULL BEFORE STARTING

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initial Setup
    ui->setupUi(this);
    resize(600, 500);
    stateManager = new StateManager(this);
}



MainWindow::~MainWindow()
{
    delete ui;
    delete stateManager;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (stateManager)
        stateManager->resize();
    QWidget::resizeEvent(event);
}
