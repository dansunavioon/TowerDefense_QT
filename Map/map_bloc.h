//
// Created by damra on 15/05/2024.
//

#ifndef PROJET_QT_MAP_BLOC_H
#define PROJET_QT_MAP_BLOC_H

#include "../DatabaseManager.h"

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
#include <QRandomGenerator>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QPushButton>

// ------------------------------------------ Herbe
class bloc_herbe : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_herbe(QGraphicsItem *parent = nullptr);
    virtual ~bloc_herbe();
};


// ------------------------------------------ Pierre
class bloc_pierre : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_pierre(QGraphicsItem *parent = nullptr);
    virtual ~bloc_pierre();

signals:
    void clicked(bloc_pierre *bloc);

protected: // permet de limiter l'appel de cette fonction (depuis l'ext)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


// ------------------------------------------ Chemin
class bloc_chemin : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bloc_chemin(QGraphicsItem *parent = nullptr);
    virtual ~bloc_chemin();
};


// ------------------------------------------ Chateau
class chateau : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    chateau(QGraphicsItem *parent = nullptr)
            : QObject(), QGraphicsPixmapItem(QPixmap(":/ressources/chateau.png"), parent), vie(100), max_vie(100) {
        progressBar = new QProgressBar();
        progressBar->setRange(0, max_vie);
        progressBar->setValue(vie);
        progressBar->update();

        //progressBar->setFixedWidth(pixmap().width());
        progressBar->setStyleSheet(
                "QProgressBar {"
                "  border: 1px solid black;"
                "  border-radius: 5px;"
                "  background: white;"
                "  text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "  background-color: #75CA3B;"
                "  border-radius: 5px;"
                "}");

        progressBar->setFormat("%p% (%v/%m)");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(progressBar);
        layout->setAlignment(Qt::AlignCenter);

        QWidget *widget = new QWidget();
        widget->setLayout(layout);
        //widget->setFixedSize(progressBar->sizeHint().width(), progressBar->sizeHint().height());

        // poxyWidget -> afficher la progressbar sur le chateau
        proxyWidget = new QGraphicsProxyWidget(this);
        proxyWidget->setWidget(widget);
        proxyWidget->setPos((pixmap().width() - widget->width()) / 2, -widget->height() - 10);

        proxyWidget->setVisible(true);
        proxyWidget->show();
    }
    virtual ~chateau();

    void perdre_vie(int degats);

signals:
    void chateauDetruit();

private:
    QProgressBar *progressBar;
    QGraphicsProxyWidget *proxyWidget;
    int vie;
    int max_vie;
};


// ------------------------------------------ Map Générale
class map_bloc : public QGraphicsScene {
    Q_OBJECT
public:
    explicit map_bloc(QObject *parent = nullptr);
    virtual ~map_bloc();
    int spawn_enemy = 0;

    void wheelEvent(QWheelEvent *event);
    void scoreUpdate(int up);

    void setPlayerPseudo(const QString &pseudo);

public slots:
    void new_tower(bloc_pierre *bloc);
    void handleChateauDetruit();

private slots:
    void updateCountdown() {
        if (countdownValue > 0) {
            countdownText->setPlainText(QString::number(countdownValue));
            countdownText->setPos((width() - countdownText->boundingRect().width()) / 2, 5);
            countdownValue--;
        } else {
            countdownText->setPlainText("START !");
            countdownText->setPos((width() - countdownText->boundingRect().width()) / 2, 5);
            countdownTimer->stop();

            spawnTimer = new QTimer(this);
            connect(spawnTimer, &QTimer::timeout, this, &map_bloc::function_spawn_enemy);
            spawnTimer->start(3000); // Crée un nouvel ennemi toutes les 3s
        }
    }

    void incrementerScore();

protected :
    void maj_game();
    void function_spawn_enemy();

signals:
    void abandonGame(); // Signal pour l'abandon

private:
    QVector<QVector<QVector<QGraphicsItem*>>> all_maps;
    QVector<QVector<QGraphicsItem*>>* selection;
    void initializeGrille(int ligne, int colonne, int squareSize, int marge);
    int tab[4] = {5, 5, 7, 3};
    map_bloc *map;
    QTimer *gameTimer;
    QTimer *spawnTimer;

    int score = 0;
    QTimer *scoreTimer;
    QGraphicsTextItem *scoreText;

    QTimer* countdownTimer;
    QGraphicsTextItem* countdownText;
    int countdownValue; // valeur initiale du compte à rebours

    QString playerPseudo;
    DatabaseManager dbManager;

    friend class enemy;
    friend class chateau;
};

#endif //PROJET_QT_MAP_BLOC_H
