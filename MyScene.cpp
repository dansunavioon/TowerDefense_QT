#include "MyScene.h"
#include <iostream>
#include <QPointF>

using namespace std;

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    QGraphicsRectItem* qgri = new QGraphicsRectItem(10, 100, 300, 200);
    this->addItem(qgri);
    QGraphicsTextItem* qgti = new QGraphicsTextItem("CIR2 Nantes");
    this->addItem(qgti);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30); //toutes les 30 millisecondes
}

MyScene::~MyScene() {


}

void MyScene::update() {
    QPointF pos = qgti->pos();
    qgti->setPos(pos.rx(), pos.ry()+50);
}
