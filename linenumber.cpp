#include "linenumber.h"
#include <QPainter>
#include <cmath>

void LineNumber::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(this->rect(), QColor::fromRgb(36, 36, 36));
    painter.setFont(*m_textEditor->font);
    painter.setPen(QPen(QColor::fromRgb(255,255,255), 1));

    int fontHeight = m_textEditor->cursorRect().height();
    int fontMetricsHeight = m_textEditor->fontMetrics().height();
    int heightOfLineNumber = m_textEditor->rect().height();
    int blockCount = m_textEditor->blockCount() + 2;
    qInfo() << "LINENUBMER HEIGHT:" << this->height() << "TEXT EDITOR:" << heightOfLineNumber << "\nFONT HEIGHT:" << fontHeight << "BLOCK COUNT:" << blockCount - 2;

    numberOfVisibleLines = (heightOfLineNumber + 2*fontHeight )/ fontHeight;

    int maxNumberToBeDrawn, minNumberToBeDrawn;
    if(blockCount > numberOfVisibleLines) {
        maxNumberToBeDrawn = blockCount;
        minNumberToBeDrawn = blockCount - numberOfVisibleLines + 1;
    } else {
        maxNumberToBeDrawn = numberOfVisibleLines;
        minNumberToBeDrawn = 1;
    }


    noOfDigits = (int) (log(maxNumberToBeDrawn) / log(10)) + 1;
    for(int i = 0; i < heightOfLineNumber; i=((int)i+fontHeight)) {
       painter.drawText(QRect(0, (int) i, this->rect().width(), fontHeight), Qt::AlignCenter, QString::number(minNumberToBeDrawn));
       minNumberToBeDrawn++;
    }
}
