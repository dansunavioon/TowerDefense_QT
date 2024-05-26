//
// Created by damra on 15/05/2024.
//

#ifndef PROJET_QT_ENEMY_H
#define PROJET_QT_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QProgressBar>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include "../Map/map_bloc.h"


class enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enemy(int ligne, int colonne, QGraphicsItem *parent = nullptr, map_bloc* mamap=nullptr, QGraphicsItem* monblocactuel=nullptr);
    virtual ~enemy();

    void recevoir_degats(int degats);
    void avancer();
    QPointF pointcentral();
    void teleport(QGraphicsItem& destination);

private slots:
    //void moveStep();
    //void startMovement();

private:
    int sante;
    int max_sante =100;
    QProgressBar *barreVie;
    QGraphicsProxyWidget *proxyWidget;
    QPointF destination; // Destination actuelle de l'ennemi
    QPointF position1;   // Position actuelle de l'ennemi
    QGraphicsItem *blocSuivant; // Bloc suivant
    map_bloc* lamap;
    float vitesse;
    QGraphicsItem* monblocactuel;
    QGraphicsItem* blocprecedent=nullptr;
    QPointF targetPosition;
    QTimer* movementTimer;


};


#endif //PROJET_QT_ENEMY_H
