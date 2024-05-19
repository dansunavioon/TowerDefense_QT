#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include "Map/map_bloc.h"
#include "Tower/tower.h"
#include "Assaillant/enemy.h"

#include <QGraphicsItem>
#include <QTimer>
#include <QVector>

class MyScene : public QGraphicsScene {
    Q_OBJECT

public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();

public slots:
    void update();

private:
    QTimer* timer = nullptr;
    QGraphicsRectItem* qgri = nullptr;
    QGraphicsTextItem* qgti = nullptr;

};


// ------------------------------------------ MENU
class Menu : public QGraphicsScene {
    Q_OBJECT
public:
    Menu(QObject* parent = nullptr);
    virtual ~Menu();

public slots:
    void update();

private:
    QGraphicsRectItem* qgri = nullptr;
    QGraphicsTextItem* qgti = nullptr;

};


// ------------------------------------------ JEU
class Game : public QGraphicsScene {
    Q_OBJECT
public:
    Game(QObject *parent = nullptr);

private:
    map_bloc *map;
};



#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
