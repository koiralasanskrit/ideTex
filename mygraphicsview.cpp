#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView()
{
    scene = new MyGraphicsScene();
    setScene(scene);
}

MyGraphicsScene::MyGraphicsScene()
{
    setSceneRect(-500, -500, 500, 500);
    QGraphicsRectItem item(10, 10, 10, 10);
    addItem(&item);
    item.setFlag(QGraphicsItem::ItemIsSelectable);
}
