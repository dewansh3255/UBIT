#include "mainwindow.h"
#include "ui_mainwindow.h"

//ALWAYS PULL BEFORE STARTING

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gif = nullptr;
    mainLayout = new QGridLayout;
    setBackground(":/res/img/blue_circle.gif");

}

MainWindow::~MainWindow()
{
    if (gif) {
        delete gif;
        delete gif_label;
    }
    delete mainLayout;
    delete ui;
}


void MainWindow::setBackground(QString path)
{
    //For gif file
    if (path[path.size()-1] == "f") {
        if (this->gif == nullptr) {
            this->gif = new QMovie(path);
            this->gif_label = new QLabel(this);
            gif_label->resize(this->width(), this->height());
        }
        else
            this->gif->setFileName(path);
        gif_label->setMovie(gif);
        gif->start();
    } else {
        QPixmap background(path);
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, background);
        this->setPalette(palette);
    }
}

