//
// Created by damra on 15/05/2024.
//

#include "map_bloc.h"
using namespace std;

// ------------------------------------------ Herbe
bloc_herbe::bloc_herbe(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/ressources/bloc_herbe.png"));
    /*
    int rotation = QRandomGenerator::global()->bounded(0, 4);
    rotation *= 90;
    setTransformOriginPoint(125/2,125/2);
    setRotation(rotation);
     */
}

bloc_herbe::~bloc_herbe() {

}


// ------------------------------------------ Pierre
bloc_pierre::bloc_pierre(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/ressources/bloc_pierre.png"));
    // qDebug() << "pierre";
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
    qDebug() << "bien entrée";
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
    all_maps.resize(5);
    all_maps[0].resize(8);
    for (int i=0;i<8;i++) all_maps[0][i].resize(12);
    all_maps[0] = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    all_maps[1].resize(8);
    for (int i=0;i<8;i++) all_maps[1][i].resize(12);
    all_maps[1] = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    all_maps[2].resize(8);
    for (int i=0;i<8;i++) all_maps[2][i].resize(12);
    all_maps[2] = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new chateau()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()}};

    all_maps[3].resize(8);
    for (int i=0;i<8;i++) all_maps[3][i].resize(12);
    all_maps[3] = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new chateau()}};

    all_maps[4].resize(8);
    for (int i=0;i<8;i++) all_maps[4][i].resize(12);
    all_maps[4] = {{new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()},
            {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()}};

    //all_maps = {map1, map2, map3, map4, map5};

    //int indice = rand()%5;
    selection = &(all_maps[1]);

    //qDebug() << indice;

    initializeGrille(8, 12, 100, 50);
}

void map_bloc::initializeGrille(int lignes, int colonnes, int squareSize, int marge) {
    int all_largeur = marge * 2 + squareSize * colonnes;
    int all_hauteur = marge * 2 + squareSize * lignes;
    this->setSceneRect(0, 0, all_largeur, all_hauteur);

    int i = 0;
    for(int ligne = 0; ligne < lignes; ++ligne) {
        for(int colonne = 0; colonne < colonnes; ++colonne) {
            if((*selection)[ligne][colonne] != nullptr) {
                int x = marge + colonne * squareSize;
                int y = marge + ligne * squareSize;
                (*selection)[ligne][colonne]->setPos(x, y);
                this->addItem((*selection)[ligne][colonne]);
                //qDebug() << "bloc";
                qDebug() << "Position de l'objet : (" << (*selection)[ligne][colonne]->x() << ", " << (*selection)[ligne][colonne]->y() << ")";
                i+=1;
            }
        }
    }
    qDebug() << i;
}

map_bloc::~map_bloc() {

}
