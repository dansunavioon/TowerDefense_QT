//
// Created by damra on 15/05/2024.
//

#include "tower.h"

tower::tower(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), degats(5), portee(150), cadence_tir(1000), cible(nullptr) {
    setPixmap(QPixmap(":/ressources/tower_basic.png"));
    // Mise à jour de la position du cercle de portée
    qreal centerX = boundingRect().center().x();
    qreal centerY = boundingRect().center().y();
    auto *cercle_range = new QGraphicsEllipseItem(centerX - portee, centerY - portee, 2 * portee, 2 * portee, this);
    cercle_range->setPen(QPen(Qt::DotLine));

    // Mécanique de tirs
    minuteur_tir = new QTimer(this);
    connect(minuteur_tir, &QTimer::timeout, this, &tower::tirer);
    minuteur_tir->start(cadence_tir);

    /*
    // Timer pour mise à jour de la cible
    minuteur_cible = new QTimer(this);
    connect(minuteur_cible, &QTimer::timeout, this, &tower::enemy_cible);
    minuteur_cible->start(500);
     */

    // Initialisation du timer d'attaque
    attaqueTimer = new QTimer(this);
    connect(attaqueTimer, &QTimer::timeout, this, &tower::tirer);
    attaqueTimer->setSingleShot(true);
    attaqueTimer->start(3000);
}

void tower::enemy_cible() {
    QList<QGraphicsItem *> allItems = scene()->items();
    for (QGraphicsItem *item : allItems) {
        enemy *ennemi = dynamic_cast<enemy*>(item);
        if (ennemi) {
            // Vérifier si l'ennemi se trouve dans la portée de la tour
            qreal distance = QLineF(mapToScene(0, 0), ennemi->mapToScene(0, 0)).length();
            if (distance <= portee) {
                ennemisDansPortee.append(ennemi);
            }
        }
    }
}


void tower::attaquer_ennemi() {
    for (enemy *ennemi : ennemisDansPortee) {
        qreal distance = QLineF(mapToScene(0, 0), ennemi->mapToScene(0, 0)).length();
        if (distance <= portee) {
            ennemi->recevoir_degats(degats);
        }
    }
}

void tower::tirer() {
    ennemisDansPortee.clear();
    enemy_cible();
    attaquer_ennemi();

    attaqueTimer->start(3000);
}


tower::~tower() {

}
