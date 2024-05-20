//
// Created by damra on 15/05/2024.
//

#include "map_bloc.h"
using namespace std;

// ------------------------------------------ Herbe
bloc_herbe::bloc_herbe(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/ressources/bloc_herbe.png"));

    int rotation = QRandomGenerator::global()->bounded(0, 360);
    setRotation(rotation);
}

bloc_herbe::~bloc_herbe() {

}


// ------------------------------------------ Pierre
bloc_pierre::bloc_pierre(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/ressources/bloc_pierre.png"));
}

void bloc_pierre::click_pierre(QGraphicsSceneMouseEvent *event) {
    // à modifier
    QMessageBox::information(nullptr, "Bloc de Pierre", "Clic sur le bloc de pierre !");
}

bloc_pierre::~bloc_pierre() {

}


// ------------------------------------------ Chemin
bloc_chemin::bloc_chemin(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/ressources/bloc_chemin.png"));
}

bloc_chemin::~bloc_chemin() {

}


// ------------------------------------------ Chateau
void chateau::perdre_vie(int degats) {
    // Réduire la vie du château et mettre à jour la barre de progression
    vie -= degats;
    progressBar->setValue(vie);
}

chateau::~chateau() {

}


// ------------------------------------------ Map Générale
map_bloc::map_bloc(QObject *parent) : QGraphicsScene(parent) {

    /* Affichage -> conception maps
    mapX = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};
    */

    map1 = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    map2 = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    map3 = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()}};

    map4 = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new chateau()}};

    map5 = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    all_maps = {map1, map2, map3, map4, map5};

    int indice = rand()%5;
    selection = all_maps[indice];

    initializeGrille(8, 12, 125, 50, selection);
}

void map_bloc::initializeGrille(int lignes, int colonnes, int squareSize, int marge, QVector<QVector<QGraphicsItem*>> map) {
    int all_largeur = marge * 2 + squareSize * colonnes;
    int all_hauteur = marge * 2 + squareSize * lignes;
    this->setSceneRect(0, 0, all_largeur, all_hauteur);

    for(int ligne = 0; ligne < lignes; ++ligne) {
        for(int colonne = 0; colonne < colonnes; ++colonne) {
            if(map[ligne][colonne] != nullptr) {
                int x = marge + colonne * squareSize;
                int y = marge + ligne * squareSize;
                map[ligne][colonne]->setPos(x, y);
                this->addItem(map[ligne][colonne]);
            }
        }
    }
}

map_bloc::~map_bloc() {

}
