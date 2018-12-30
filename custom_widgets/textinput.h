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

    //Components
    QPlainTextEdit *textEdit;
    QPushButton *pushButton;
signals:

public slots:

    void loadInput();
private:
};

#endif // TEXTINPUT_H
