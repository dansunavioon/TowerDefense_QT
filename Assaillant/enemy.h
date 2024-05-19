//
// Created by damra on 15/05/2024.
//

#ifndef PROJET_QT_ENEMY_H
#define PROJET_QT_ENEMY_H

#include <QGraphicsPixmapItem>
#include <QProgressBar>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>

class enemy : public QGraphicsPixmapItem {
public:
    enemy(int ligne, int colonne, QGraphicsItem *parent = nullptr);

    void recevoir_degats(int degats);
    void avancer();

private:
    int sante;
    int max_sante;
    QProgressBar *barreVie;
    QGraphicsProxyWidget *proxyWidget;
    QPointF position1;
};


#endif //PROJET_QT_ENEMY_H
