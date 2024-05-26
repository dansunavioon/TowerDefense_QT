//
// Created by damra on 15/05/2024.
//

#include "enemy.h"
#include <iostream>
#include <QGraphicsScene>
#include "../Map/map_bloc.h"

enemy::enemy(int ligne, int colonne, QGraphicsItem *parent, map_bloc* mamap, QGraphicsItem* monblocactuel) : QObject(), QGraphicsPixmapItem(parent), sante(100), lamap(mamap), monblocactuel(monblocactuel) {
    qDebug() << "enemy créé";
    setPixmap(QPixmap(":/ressources/enemy_basic.png"));

    setPos(colonne * 100 + 50,ligne  * 100 + 50);
    position1 = pos();
    qDebug() << position1;

    barreVie = new QProgressBar();
    barreVie->setRange(0, max_sante);
    barreVie->setValue(sante);
    barreVie->update();
    //barreVie->setFixedWidth(100);
    //barreVie->setFixedHeight(10);

    barreVie->setStyleSheet(
            "QProgressBar {"
            "  border: 1px solid black;"
            "  border-radius: 5px;"
            "  background: white;"
            "  text-align: center;"
            "}"
            "QProgressBar::chunk {"
            "  background-color: #FC6240;"
            "  border-radius: 5px;"
            "}");

    barreVie->setFormat("%p% (%v/%m)");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(barreVie);
    layout->setAlignment(Qt::AlignCenter);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    //widget->setFixedSize(100, 20);

    // poxyWidget -> afficher la progressbar sur l'enemy
    proxyWidget = new QGraphicsProxyWidget(this);
    proxyWidget->setWidget(widget);
    proxyWidget->setPos((pixmap().width() - widget->width()) / 2, -widget->height() - 10);

    destination = pos();
    blocSuivant = nullptr;

    proxyWidget->setVisible(true);
    proxyWidget->show();
}

void enemy::recevoir_degats(int degats) {
    sante -= degats;
    if(sante <= 0){
        scene()->removeItem(this);
        delete this;
    } else{
        barreVie->setValue(sante);
        barreVie->update();
    }
}

float distance_euclidienne(float xa, float xb, float ya, float yb)
{
    return sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
}

float distance_QpointF(QPointF A, QPointF B)
{
    return(distance_euclidienne(A.x(),B.x(),A.y(),B.y()));
}

float distance_deux_bloc(const QGraphicsItem& A, const QGraphicsItem& B)
{
    return(distance_euclidienne(A.x(),B.x(),A.y(),B.y()));
}

float distance_bloc_QPOINT(const QGraphicsItem& A, QPointF B)
{
    return(distance_euclidienne(A.x(),B.x(),A.y(),B.y()));
}

QPointF pointcentralBloc(QGraphicsItem& bloc){
    QPointF retour;
    QRectF bounding=bloc.boundingRect();
    retour.setX(bloc.pos().x()+bounding.width()/2);
    retour.setY(bloc.pos().y()+bounding.height()/2);
    return retour;
}


QPointF enemy::pointcentral(){
    QPointF retour;
    QRectF bounding=boundingRect();
    retour.setX(pos().x()+bounding.width()/2);
    retour.setY(pos().y()+bounding.height()/2);
    return retour;
}

void enemy::teleport(QGraphicsItem& destination)
{
    setPos(destination.pos());
    blocprecedent = monblocactuel;
    monblocactuel = blocSuivant;
    blocSuivant=nullptr;
/*
    blocprecedent = monblocactuel;
    monblocactuel = &destination;
    blocSuivant = nullptr;*/
}

void enemy::avancer() {

    float distance_min = 100000;
    QGraphicsItem* blocPlusProche=nullptr;

    for(auto& ligne : *(lamap->selection)) {
        for(auto& bloc : ligne) {
            bloc_chemin *chemin = dynamic_cast<bloc_chemin*>(bloc);
            if(bloc != monblocactuel && bloc != blocprecedent && chemin != nullptr) {
                float distance = distance_QpointF(pointcentralBloc(*bloc), pointcentral());
                if (distance < distance_min) {
                    distance_min = distance;
                    blocPlusProche = bloc;
                }
            } else {
                chateau *chateauB = dynamic_cast<chateau*>(bloc);
                if(chateauB != nullptr) {
                    // Le bloc est un château
                    float distance = distance_QpointF(pointcentralBloc(*bloc), pointcentral());
                    if (distance < distance_min) {
                        distance_min = distance;
                        blocPlusProche = bloc;
                    }
                }
            }
        }
    }

    // Vérifier si blocPlusProche est un château
    chateau *chateauB = dynamic_cast<chateau*>(blocPlusProche);
    if(chateauB != nullptr) {
        recevoir_degats(100); // detruit l'enemy
        chateauB->perdre_vie(10);
        return;
    } else {
        blocSuivant = blocPlusProche;
        teleport(*blocSuivant);

        //startMovement();
    }
}

/*

void enemy::startMovement() {
    if (movementTimer != nullptr) {
        movementTimer->stop();
        delete movementTimer;
    }

    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &enemy::moveStep);
    movementTimer->start(30); // Déplace l'ennemi toutes les 30ms

    targetPosition = pointcentralBloc(*blocSuivant);
}

void enemy::moveStep() {
    QPointF currentPosition = pos();
    QPointF direction = targetPosition - currentPosition;
    float distance = sqrt(pow(direction.x(), 2) + pow(direction.y(), 2));

    if (distance <= vitesse) {
        setPos(targetPosition);
        movementTimer->stop();
        teleport(*blocSuivant); // Met à jour les pointeurs pour le prochain mouvement
    } else {
        qreal ratio = vitesse / distance;
        QPointF step = direction * ratio;
        setPos(currentPosition + step);
    }
}*/


enemy::~enemy() {

}
