#include "myplaintextedit.h"

MyPlainTextEdit::MyPlainTextEdit() {
    font = new QFont("Sanskrit Text");
    font->setPointSize(16);
    setFont(*font);
    setPlaceholderText("विलिख्यताम्....");
    setCursorWidth(5);
    setStyleSheet("MyPlainTextEdit { color: rgb(255, 255, 255); }");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MyPlainTextEdit::wheelEvent(QWheelEvent *w) {
   // do nothing
}
