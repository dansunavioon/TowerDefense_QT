#include "MainWindow.h"
#include "Map/map_bloc.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->mainScene = new Menu(this);

    this->mainView = new QGraphicsView(this);
    this->mainView->setScene(mainScene);
    /*
    this->mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    */
    this->setCentralWidget(this->mainView);

    this->setWindowTitle("Tower Defense by StudioXY");

    connect(mainScene, &Menu::start_game_signal, this, &MainWindow::start_game);
}


MainWindow::~MainWindow(){

}

void MainWindow::start_game(const QString &pseudo) {
    this->mainView->setFixedSize(1300, 900);
    this->secondeScene = new map_bloc(this);
    this->mainView->setScene(secondeScene);
    connect(secondeScene, &map_bloc::abandonGame, this, &MainWindow::retournerAuMenu);

    secondeScene->setPlayerPseudo(pseudo);

    // Activer le défilement avec la molette de la souris
    this->mainView->setMouseTracking(true);
    this->mainView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->mainView->viewport()->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    // inspiré de mes recherches
    if (event->type() == QEvent::Wheel && obj == this->mainView->viewport()) {
        QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);
        this->secondeScene->wheelEvent(wheelEvent);
        return true;
    }
    return false;
}

void MainWindow::retournerAuMenu() {
    this->mainScene = new Menu(this);

    this->mainView = new QGraphicsView(this);
    this->mainView->setScene(mainScene);

    this->setCentralWidget(this->mainView);

    this->setWindowTitle("Tower Defense by StudioXY");

    connect(mainScene, &Menu::start_game_signal, this, &MainWindow::start_game);
}
