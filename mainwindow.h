#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeBackground(QMovie* background);

private:
    Ui::MainWindow *ui;
    QMovie* background;
};

#endif // MAINWINDOW_H
