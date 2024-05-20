//
// Created by damra on 15/05/2024.
//

#include "enemy.h"
#include <QGraphicsScene>

enemy::enemy(int ligne, int colonne, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), sante(100) {
    setPixmap(QPixmap(":/ressources/test_enemy.png"));

    setPos(colonne * 125, ligne * 125);
    position1 = pos();

    barreVie = new QProgressBar();
    barreVie->setRange(0, max_sante);
    barreVie->setValue(sante);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(barreVie);
    layout->setAlignment(Qt::AlignCenter);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // poxyWidget -> afficher la progressbar sur l'enemy
    proxyWidget = new QGraphicsProxyWidget(this);
    proxyWidget->setWidget(widget);
    proxyWidget->setPos((pixmap().width() - widget->width()) / 2, (pixmap().height() - widget->height()) / 2);
}

void enemy::recevoir_degats(int degats) {
    sante -= degats;
    if(sante <= 0){
        scene()->removeItem(this);
        delete this;
    } else{
        barreVie->setValue(sante);
    }
}

void enemy::avancer() {
    // a compléter
}

enemy::~enemy() {

}
