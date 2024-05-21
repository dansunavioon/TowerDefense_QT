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
#include <QGraphicsView>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QScrollBar>


// ------------------------------------------ MENU
class Menu : public QGraphicsScene {
    Q_OBJECT
public:
    Menu(QObject* parent = nullptr);
    virtual ~Menu();

signals:
    void start_game_signal(QString pseudo);

private slots:
    void askPseudo();

protected:
    void zoom(QWheelEvent *event);
    void deplacement_fleche(QKeyEvent *event);

private:
    // QWidget* mainWindow;
   // QGraphicsView* mainView;
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
  //  QGraphicsView *mainView;
    map_bloc *map;
};



#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
