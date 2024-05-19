//
// Created by damra on 15/05/2024.
//

#include "tower.h"

tower::tower(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), degats(10), portee(100), cadence_tir(1000), cible(nullptr) {
    setPixmap(QPixmap(":/ressources/test_tower.png"));
    // mecanique de tirs
    minuteur_tir = new QTimer(this);
    connect(minuteur_tir, &QTimer::timeout, this, &tower::tirer);
    minuteur_tir->start(cadence_tir);

    auto *cercle_range = new QGraphicsEllipseItem(-portee, -portee, 2 * portee, 2 * portee, this);
    cercle_range->setPen(QPen(Qt::DotLine));
}

void tower::enemy_cible() {
    // crée le bon polygone de la portee
    QList<QGraphicsItem *> items_proches = scene()->items(QPolygonF() << mapToScene(0, 0) << mapToScene(0, 1) << mapToScene(1, 0) << mapToScene(1, 1));
    qreal distance_min = portee;
    QGraphicsItem *nouvelle_cible = nullptr;

    for (QGraphicsItem *item : items_proches) {
        // retourne un pointeur vers l'objet convertie car meme instance
        enemy *ennemi = qgraphicsitem_cast<enemy*>(item);
        if (ennemi) {
            qreal distance = QLineF(mapToScene(0, 0), ennemi->mapToScene(0, 0)).length();
            if (distance <= distance_min) {
                distance_min = distance;
                nouvelle_cible = ennemi;
            }
        }
    }
    // maj cible
    cible = dynamic_cast<enemy *>(nouvelle_cible);
}

void tower::attaquer_ennemi() {
    if (cible) {
        // si dans la portee
        qreal distance = QLineF(mapToScene(0, 0), cible->mapToScene(0, 0)).length();
        if (distance <= portee) {
            // attaquer
            enemy *ennemi = qgraphicsitem_cast<enemy*>(cible);
            if (ennemi) {
                ennemi->recevoir_degats(degats);
            }
        }
    }
}

void tower::tirer() {
    enemy_cible();
    attaquer_ennemi();
}
