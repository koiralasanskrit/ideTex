#ifndef LINENUMBER_H
#define LINENUMBER_H

#include <QWidget>
#include "myplaintextedit.h"

class LineNumber : public QWidget
{
    Q_OBJECT
public:
    LineNumber(QWidget *parent = nullptr, QFont* font = nullptr, MyPlainTextEdit* textEditor = nullptr) : QWidget(parent), m_parentWidget(parent), m_font(font), m_textEditor(textEditor){
        noOfDigits = 2;
        setStyleSheet("QWidget {background-color: rgb(36,36,36); }");
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        connect(m_textEditor, &MyPlainTextEdit::cursorPositionChanged, this, &LineNumber::highlightCurrentLine);
        connect(m_textEditor, &MyPlainTextEdit::cursorPositionChanged, this, &LineNumber::updateLineNumberWidth);
        connect(m_textEditor, &MyPlainTextEdit::blockCountChanged, this, &LineNumber::updateLineNumbers);
        connect(m_textEditor, &MyPlainTextEdit::cursorPositionChanged, this, &LineNumber::updateLineNumbers);
        width = m_textEditor->fontMetrics().horizontalAdvance(QLatin1Char('9'))*noOfDigits;
        int fontHeight = m_textEditor->cursorRect().height();
        int heightOfLineNumber = m_textEditor->rect().height();
        numberOfVisibleLines = (heightOfLineNumber + fontHeight*2) / fontHeight;
        numberOfLines = numberOfVisibleLines;
        setMinimumWidth(width);
    }
    ~LineNumber() {
        delete m_parentWidget;
        delete m_font;
        delete m_textEditor;
    }

    QSize sizeHint() const override {
       return QSize(10, m_parentWidget->size().height());
    }

    void paintEvent(QPaintEvent* painter) override;

    // so called private;
    QWidget* m_parentWidget;
    QFont* m_font;
    MyPlainTextEdit* m_textEditor;
    int width;
    int noOfDigits;
    int numberOfLines;
    int numberOfVisibleLines;

public slots:
    void updateLineNumberWidth() {
        if(noOfDigits > 2) {
            width = m_textEditor->fontMetrics().horizontalAdvance(QLatin1Char('9'))*noOfDigits;
            setMinimumWidth(width);
                this->update();
        }
    }

    void highlightCurrentLine() {

    }

    void updateLineNumbers() {
       numberOfLines = m_textEditor->blockCount();
       this->update();
    }
};

#endif // LINENUMBER_H
