#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

//QT Classes
#include <QtWidgets>
#include <QLayout>


class ScreenManager
{
public:
    ScreenManager();
    ~ScreenManager();
    //Widgets
    void addUiElements(QWidget* widget, QGroupBox *group);
    //Background
    void setBackground(QString path, QWidget* window);

private:
    //Main Window
    QLayout* mainLayout;
    //Background
    QMovie* gif;
    QLabel* gif_label;
    QString background;

};

#endif // SCREENMANAGER_H
