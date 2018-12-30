#include "processbutton.h"

ProcessButton::ProcessButton(QVector <QPlainTextEdit*> inputs, QWidget *parent) : QPushButton("Process", parent)
{
    this->inputs = inputs;
}

void ProcessButton::mousePressEvent(QMouseEvent* e) {
    QVector <QString> inputs;
    for (int i = 0; i < this->inputs.size(); i++) {
        inputs.push_back(this->inputs[i]->toPlainText());
        this->inputs[i]->clear();
    }
    emit sendText(inputs);
}
