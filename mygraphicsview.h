#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class MyGraphicsScene : public QGraphicsScene
{
public:
    MyGraphicsScene();
};


class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView();
private:
    MyGraphicsScene *scene;
};

#endif // MYGRAPHICSVIEW_H
