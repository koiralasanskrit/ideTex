#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include <QPlainTextEdit>

class MyPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    MyPlainTextEdit();
    ~MyPlainTextEdit() {
        delete font;
    }
    QFont *font;
    void wheelEvent(QWheelEvent *e) override;
};

#endif // MYPLAINTEXTEDIT_H
