#include "mainwindow.h"

MainWindow::MainWindow(QWidget *widget) {
    splitter = new QSplitter();
    splitter->setOrientation(Qt::Horizontal);
    plainEdit = new MyPlainTextEdit();
    linenum = new LineNumber(splitter, plainEdit->font, plainEdit);
    gView = new MyGraphicsView();
    gView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    gView->setMinimumWidth(10);
    splitter->addWidget(gView);
    splitter->addWidget(linenum);
    splitter->addWidget(plainEdit);
    splitter->setHandleWidth(1);
    ui = new Ui::MainWindow();
    ui->setupUi(this);
    ui->widget_2->setMinimumHeight(30);
    ui->horizontalLayout->addWidget(splitter);

    ui->label_3->setText("NORMAL");
    ui->label_2->setText("TEX");
    connect(plainEdit, &MyPlainTextEdit::cursorPositionChanged, this, &MainWindow::updateBottomBar);
    updateBottomBar();
}
