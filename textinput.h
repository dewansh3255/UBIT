#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QWidget>
#include <QtWidgets>

class TextInput : public QWidget
{
    Q_OBJECT
public:
    explicit TextInput(QWidget *parent = nullptr);
    void show();
    friend class State;
signals:

public slots:

private:
    QTextEdit *textEdit;
    QPushButton *pushButton;
};

#endif // TEXTINPUT_H
