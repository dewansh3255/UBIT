#include "textinput.h"

TextInput::TextInput(QWidget *parent) : QWidget(parent)
{
    textEdit = new QPlainTextEdit(parent);
    pushButton = new QPushButton("Load Input", parent);
    //Connect button to text box
    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(loadInput()));
}

void TextInput::loadInput () {
    QString path = QFileDialog::getOpenFileName(textEdit->parentWidget(),
                                                tr("Open File"), "",
                                                tr("Text Files (*.txt);;All Files (*.*)"));
    if (path == "")
        return;
    QFile file(path);
    QString text;
    if (!file.open(QFile::ReadOnly | QFile::Text))
        text = "File not found.";
    else {
        QTextStream in(&file);
        text = in.readAll();
    }
    textEdit->setPlainText(text);
}

void TextInput::show() {
    textEdit->show();
    pushButton->show();
}
