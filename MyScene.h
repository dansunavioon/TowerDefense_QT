#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include "Map/map_bloc.h"
#include "Tower/tower.h"
#include "Assaillant/enemy.h"

#include <QGraphicsItem>
#include <QTimer>
#include <QVector>
#include <iostream>
#include <QPointF>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
#include <QWidget>
#include <QInputDialog>
#include <QLabel>
#include <QPixmap>
#include <QDebug>


// ------------------------------------------ MENU
class Menu : public QGraphicsScene {
    Q_OBJECT
public:
    Menu(QObject* parent = nullptr);
    virtual ~Menu();

private slots:
    void askPseudo();

private:
    // QWidget* mainWindow;
    QPushButton  *playButton = nullptr;
    QPushButton  *settingsButton = nullptr;
    QPushButton  *classementButton = nullptr;
    QString pseudo;
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
