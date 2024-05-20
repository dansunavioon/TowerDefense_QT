#include "MainWindow.h"

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

void MainWindow::start_game(QString pseudo) {
    this->mainView->setFixedSize(1600, 1100);
    this->secondeScene = new Game(this);
    this->mainView->setScene(secondeScene);
}
