#include "textinput.h"

TextInput::TextInput(QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit(parent);
    pushButton = new QPushButton("Load Input", parent);
}

void TextInput::show() {
    textEdit->show();
    pushButton->show();
}
