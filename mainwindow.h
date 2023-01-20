#pragma once

#include <QSplitter>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "myplaintextedit.h"
#include "linenumber.h"
#include "mygraphicsview.h"

// आफ्नो main विन्डो बनाएको मात्र हो
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {
        delete splitter;
        delete gView;
        delete plainEdit;
        delete ui;
    }

private:
    QSplitter* splitter;
    MyGraphicsView* gView;
    QOpenGLWidget* opengl;
    MyPlainTextEdit* plainEdit;
    LineNumber* linenum;
    Ui::MainWindow *ui;

public slots:
    void updateBottomBar() {
        QString str = "LINE:" + QString::number(linenum->numberOfLines);
        ui->label->setText(str);
        ui->label->update();
    }
};


