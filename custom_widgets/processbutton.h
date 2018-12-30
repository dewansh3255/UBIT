#ifndef PROCESSBUTTON_H
#define PROCESSBUTTON_H

#include <QWidget>
#include <QtWidgets>

//Custom Classes
#include "textinput.h"

class ProcessButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ProcessButton(QVector <QPlainTextEdit*> inputs, QWidget *parent = nullptr);
signals:
    void sendText(QVector <QString> input);

public slots:
    void mousePressEvent(QMouseEvent* e) override;

private:
    QVector <QPlainTextEdit*> inputs;
};

#endif // PROCESSBUTTON_H
