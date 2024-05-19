//
// Created by damra on 15/05/2024.
//

#ifndef PROJET_QT_MAP_BLOC_H
#define PROJET_QT_MAP_BLOC_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QProgressBar>
#include <QVector>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>

// ------------------------------------------ Herbe
class bloc_herbe : public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_herbe(QGraphicsItem *parent = nullptr);
};

// ------------------------------------------ Pierre
class bloc_pierre : public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_pierre(QGraphicsItem *parent = nullptr);
protected: // permet de limiter l'appel de cette fonction (depuis l'ext)
    void click_pierre(QGraphicsSceneMouseEvent *event);
};

// ------------------------------------------ Chemin
class bloc_chemin : public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_chemin(QGraphicsItem *parent = nullptr);
};

// ------------------------------------------ Chateau
class chateau : public QGraphicsPixmapItem {
    Q_OBJECT
public:
    chateau(QGraphicsItem *parent = nullptr) : QGraphicsPixmapItem(QPixmap(":/ressources/chateau.png"), parent), vie(100), maxVie(100) {
        progressBar = new QProgressBar();
        progressBar->setRange(0, maxVie);
        progressBar->setValue(vie);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(progressBar);
        layout->setAlignment(Qt::AlignCenter);

        QWidget *widget = new QWidget();
        widget->setLayout(layout);

        // poxyWidget -> afficher la progressbar sur le chateau
        proxyWidget = new QGraphicsProxyWidget(this);
        proxyWidget->setWidget(widget);
        // centre horizontalement et met la barre en bas
        proxyWidget->setPos((pixmap().width() - widget->width()) / 2, pixmap().height());
    }

    void perdre_vie(int degats);

private:
    QProgressBar *progressBar;
    QGraphicsProxyWidget *proxyWidget;
    int vie;
    int maxVie;
};

// ------------------------------------------ Map Générale
class map_bloc : public QGraphicsScene {
    Q_OBJECT
public:
    explicit map_bloc(QObject *parent = nullptr);
    // ~map_bloc(); pour le moment non utile

private:
    QVector<QVector<QGraphicsItem*>> grille;
    void initializeGrille(int ligne, int colonne, int squareSize, int marge);

};

#endif //PROJET_QT_MAP_BLOC_H
