#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QLayout>


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

    //GUI

    //Widgets
    void addUiElements(QWidget* widget, QGroupBox *group);
    //Background
    void setBackground(QString path);

private:
    Ui::MainWindow *ui;
    QLayout* mainLayout;
    //Background
    QMovie* gif;
    QLabel* gif_label;
    QString background;
};

#endif // MAINWINDOW_H
