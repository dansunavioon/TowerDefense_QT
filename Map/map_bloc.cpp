//
// Created by damra on 15/05/2024.
//

#include "map_bloc.h"

// ------------------------------------------ Herbe
bloc_herbe::bloc_herbe(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/ressources/bloc_herbe.png");
    setPixmap(pixmap);

    int rotation = QRandomGenerator::global()->bounded(0, 360);
    setRotation(rotation);
}

// ------------------------------------------ Pierre
bloc_pierre::bloc_pierre(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/ressources/bloc_pierre.png");
    setPixmap(pixmap);
}

void bloc_pierre::click_pierre(QGraphicsSceneMouseEvent *event) {
    // à modifier
    QMessageBox::information(nullptr, "Bloc de Pierre", "Clic sur le bloc de pierre !");
}

// ------------------------------------------ Chemin
bloc_chemin::bloc_chemin(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/ressources/bloc_chemin.png");
    setPixmap(pixmap);
}

// ------------------------------------------ Chateau
void chateau::perdre_vie(int degats) {
    // Réduire la vie du château et mettre à jour la barre de progression
    vie -= degats;
    progressBar->setValue(vie);
}

// ------------------------------------------ Map Générale
map_bloc::map_bloc(QObject *parent) : QGraphicsScene(parent) {
    initializeGrille(8, 12, 125, 50);
}

/*
map_bloc::~map_bloc() {
    for(int ligne = 0; ligne < grille.size(); ++ligne) {
        for(int colonne = 0; colonne < grille[ligne].size(); ++colonne) {
            delete grille[ligne][colonne];
        }
    }
}
pour le moment non utile */

void map_bloc::initializeGrille(int lignes, int colonnes, int squareSize, int marge) {
    int all_largeur = marge * 2 + squareSize * colonnes;
    int all_hauteur = marge * 2 + squareSize * lignes;
    this->setSceneRect(0, 0, all_largeur, all_hauteur);

    QVector<QGraphicsItem*> l0 = {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe()};
    QVector<QGraphicsItem*> l1 = {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new chateau()};
    QVector<QGraphicsItem*> l2 = {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()};
    QVector<QGraphicsItem*> l3 = {new bloc_herbe(), new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()};
    QVector<QGraphicsItem*> l4 = {new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe()};
    QVector<QGraphicsItem*> l5 = {new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()};
    QVector<QGraphicsItem*> l6 = {new bloc_pierre(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_chemin(), new bloc_chemin(), new bloc_chemin(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe()};
    QVector<QGraphicsItem*> l7 = {new bloc_herbe(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_pierre(), new bloc_pierre(), new bloc_pierre(), new bloc_herbe(), new bloc_herbe(), new bloc_herbe()};

    grille = {l0, l1, l2, l3, l4, l5, l6, l7};

    for(int ligne = 0; ligne < lignes; ++ligne) {
        for(int colonne = 0; colonne < colonnes; ++colonne) {
            if(grille[ligne][colonne] != nullptr) {
                int x = marge + colonne * squareSize;
                int y = marge + ligne * squareSize;
                grille[ligne][colonne]->setPos(x, y);
                this->addItem(grille[ligne][colonne]);
            }
        }
    }
}
