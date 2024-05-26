//
// Created by damra on 15/05/2024.
//

#include "map_bloc.h"
#include "../Tower/tower.h"
#include "../MainWindow.h"
#include <QWheelEvent>

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

void bloc_pierre::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // à modifier
    emit clicked(this);
    QGraphicsPixmapItem::mousePressEvent(event);
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

    // Vérifier si la vie est inférieure ou égale à 0
    if (vie <= 0) {
        emit chateauDetruit();
    }
}

chateau::~chateau() {

}


// ------------------------------------------ Map Générale
map_bloc::map_bloc(QObject  *parent) : QGraphicsScene(parent), countdownValue(3) {
    qDebug() << "bien entrée";

    // Création du bouton Abandonner
    QPushButton *abandonButton = new QPushButton("Abandonner");
    abandonButton->setStyleSheet("background-color: red; color: white; border: 2px solid black; padding: 5px;");
    connect(abandonButton, &QPushButton::clicked, this, &map_bloc::abandonGame);
    addWidget(abandonButton);
    abandonButton->setGeometry(55, 5, 100, 40); // Position et taille du bouton

    // Création du texte du compte à rebours
    countdownText = new QGraphicsTextItem();
    countdownText->setDefaultTextColor(Qt::black);
    countdownText->setFont(QFont("Arial", 24));
    addItem(countdownText);

    // Création du timer pour le compte à rebours
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &map_bloc::updateCountdown);
    countdownTimer->start(1000); // Déclenche l'updateCountdown() toutes les secondes


    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &map_bloc::maj_game);
    gameTimer->start(1000); // Met à jour le jeu toutes les 30ms



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

    /*
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
    */
    //all_maps = {map1, map2, map3, map4, map5};

    int indice = QRandomGenerator::global()->bounded(4);
    selection = &(all_maps[indice]);
    spawn_enemy = tab[indice];

    //qDebug() << indice;

    initializeGrille(8, 12, 100, 50);
}

void map_bloc::initializeGrille(int lignes, int colonnes, int squareSize, int marge) {
    int all_largeur = marge * 2 + squareSize * colonnes;
    int all_hauteur = marge * 2 + squareSize * lignes;
    this->setSceneRect(0, 0, all_largeur, all_hauteur);

    //int i = 0;
    for (int ligne = 0; ligne < lignes; ++ligne) {
        for (int colonne = 0; colonne < colonnes; ++colonne) {
            if ((*selection)[ligne][colonne] != nullptr) {
                int x = marge + colonne * squareSize;
                int y = marge + ligne * squareSize;
                (*selection)[ligne][colonne]->setPos(x, y);
                this->addItem((*selection)[ligne][colonne]);

                bloc_pierre *pierre = dynamic_cast<bloc_pierre *>((*selection)[ligne][colonne]);
                if (pierre) {
                    connect(pierre, &bloc_pierre::clicked, this, &map_bloc::new_tower);
                }

                chateau *castle = dynamic_cast<chateau *>((*selection)[ligne][colonne]);
                if (castle) {
                    connect(castle, &chateau::chateauDetruit, this, &map_bloc::handleChateauDetruit);
                }

                //qDebug() << "bloc";
                //qDebug() << "Position de l'objet : (" << (*selection)[ligne][colonne]->x() << ", " << (*selection)[ligne][colonne]->y() << ")";
                //i+=1;
            }
        }
    }
    //qDebug() << i;
}

map_bloc::~map_bloc() {

}

void map_bloc::handleChateauDetruit() {
    // arrêter les timers
    countdownTimer->stop();
    gameTimer->stop();
    if (spawnTimer) {
        spawnTimer->stop();
    }

    // fenêtre de dialogue avec le score et un bouton recommencer
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle("Game Over");

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *scoreLabel = new QLabel("Score: ...");
    QPushButton *recommencerButton = new QPushButton("Recommencer");

    recommencerButton->setStyleSheet("background-color: green; color: white; border: 2px solid black; padding: 5px;");

    layout->addWidget(scoreLabel);
    layout->addWidget(recommencerButton);
    dialog->setLayout(layout);

    connect(recommencerButton, &QPushButton::clicked, this, [=, this]() {
        dialog->accept(); // Fermer la fenêtre de dialogue
        emit abandonGame(); // le signal pour retourner au menu et recommencer
    });

    dialog->exec();
}

void map_bloc::new_tower(bloc_pierre *bloc){
    tower *tour = new tower();
    tour->setPos(bloc->x(), bloc->y());
    this->addItem(tour);
}


void map_bloc::maj_game() { // met à jour le jeu
    QList<QGraphicsItem *> ennemis = items(); // stocke tous les ennemis
    //std::cout << "test appel maj" << endl;
    for (QGraphicsItem *item : ennemis) {
        enemy *ennemi = dynamic_cast<enemy*>(item);
        if (ennemi!=NULL) {
            ennemi->avancer();
        }
    }
}

void map_bloc::function_spawn_enemy() {
    enemy *new_enemy = new enemy(spawn_enemy, 0, nullptr, this, (*selection)[spawn_enemy][0]);
    this->addItem(new_enemy);
}

void map_bloc::wheelEvent(QWheelEvent *event) {
    // Récupérer le delta de la molette
    QPoint angleDelta = event->angleDelta();
    int delta = angleDelta.y(); // Utiliser le composant y comme delta

    if (delta > 0) {
        // Zoom avant
        views()[0]->scale(1.1, 1.1); // + 109%
    } else {
        // Zoom arrière
        views()[0]->scale(0.9, 0.9); // - 10%
    }
}