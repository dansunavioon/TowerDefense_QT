#include "MyScene.h"
#include <iostream>
#include <QPointF>

using namespace std;

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    qgri = new QGraphicsRectItem(10, 100, 300, 200);
    this->addItem(qgri);
    qgti = new QGraphicsTextItem("CIR2 Nantes");
    this->addItem(qgti);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyScene::update);
    timer->start(30); //toutes les 30 millisecondes
}

MyScene::~MyScene() {


}

void MyScene::update() {
    QPointF pos = qgti->pos();
    qDebug() << pos;
    qgti->setPos(pos.rx(), pos.ry()+1);
}
