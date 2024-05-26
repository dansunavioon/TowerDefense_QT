//
// Created by damra on 15/05/2024.
//

#ifndef PROJET_QT_TOWER_H
#define PROJET_QT_TOWER_H

#include "../Assaillant/enemy.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QPen>
#include <QDebug>
#include <QObject>
#include <QList>

class tower : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    tower(QGraphicsItem *parent = nullptr);
    virtual ~tower();

    void enemy_cible();
    void attaquer_ennemi();

private slots:
    void tirer();

private:

    int degats;
    qreal portee;
    int cadence_tir;
    QTimer *minuteur_tir;
    // QTimer *minuteur_cible;
    QTimer *attaqueTimer;
    enemy *cible;
    QList<enemy*> ennemisDansPortee;
};


#endif //PROJET_QT_TOWER_H
